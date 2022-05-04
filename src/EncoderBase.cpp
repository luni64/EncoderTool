#include "EncoderBase.h"

namespace EncoderTool
{
    EncoderBase& EncoderBase::setCountMode(CountMode mode)
    {
        switch (mode)
        {
            case CountMode::quarter:
                stateMachine = &stateMachineQtr;
                invert = 0b11;
                break;
            case CountMode::quarterInv:
                stateMachine = &stateMachineQtr;
                invert = 0b00;
                break;
            case CountMode::half:
                stateMachine = &stateMachineHalf;
                invert = 0b00;
                break;
            case CountMode::halfAlt:
                stateMachine = &stateMachineHalf;
                invert = 0b01;
                break;
            default:
                stateMachine = &stateMachineFull;
                invert = 0b00;
        }
        return *this;
    }

    EncoderBase& EncoderBase::attachCallback(encCallback_t cb)
    {
        callback = cb;
        return *this;
    }

    EncoderBase& EncoderBase::attachButtonCallback(encBtnCallback_t cb)
    {
        btnCallback = cb;
        return *this;
    }

    EncoderBase& EncoderBase::setLimits(int32_t min, int32_t max, bool periodic)
    {
        if (min < max)
        {
            this->minVal = min;
            this->maxVal = max;
            this->periodic = periodic;
        } else
        {
            this->minVal = INT32_MIN;
            this->maxVal = INT32_MAX;
        }
        return *this;
    }

    enum states : uint8_t {
        A = 0x00,
        B_cw = 0x01,
        C_cw = 0x03,
        D_cw = 0x02,
        B_ccw = 0x04,
        C_ccw = 0x06,
        D_ccw = 0x05,

        UP = 0x10,
        DOWN = 0x20,
        ERR = 0x30,
    };

    void EncoderBase::begin(uint32_t phaseA, uint32_t phaseB)
    {
        curState = (phaseA << 1 | phaseB) ^ invert;
    }

    int EncoderBase::update(uint32_t phaseA, uint32_t phaseB, uint32_t btn)
    {
        if (button.update(btn))
        {
            btnChanged = true;
            if (btnCallback != nullptr) { btnCallback(button.read()); }
        }

        unsigned input = (phaseA << 1 | phaseB) ^ invert; // invert signals if necessary
        if (stateMachine == nullptr) return 0;            // tick might get called from yield before class is initialized

        curState = (*stateMachine)[curState][input]; // get next state depending on new input
        uint8_t direction = curState & 0xF0;         // direction is set if we need to count up / down or got an error
        curState &= 0x0F;                            // remove the direction info from state

        if (direction == UP)
        {
            if (value < maxVal) // maxVal = INT_MAX if no limits set
            {
                value++;
                valChanged = true;
                if (callback != nullptr)
                    callback(value, +1);
                return +1;
            }
            if (periodic) // if periodic, wrap to minVal, else stop counting
            {
                value = minVal;
                valChanged = true;

                if (callback != nullptr)
                    callback(value, +1);
                return +1;
            }
            value = maxVal;
            return false;
        }

        if (direction == DOWN)
        {
            if (value > minVal) // minVal = INT_MIN if no limits set
            {
                value--;
                valChanged = true;
                if (callback != nullptr)
                    callback(value, -1);
                return -1;
            }
            if (periodic) // if periodic, wrap to maxVal, else stop counting
            {
                valChanged = true;
                value = maxVal;
                if (callback != nullptr)
                    callback(value, -1);
                return -1;
            }
            value = minVal;
            return 0;
        }

#if defined(USE_ERROR_CALLBACKS)
        if (direction == ERR)
        {
            if (errCallback != nullptr)
                errCallback(value);
        }
#endif
        return false;
    }

    const uint8_t EncoderBase::stateMachineQtr[7][4]{
        //             00         01          10         11
        /*0 A   */ {A, B_cw, D_ccw, A | ERR},
        /*1 B_cw*/ {A, B_cw, B_cw | ERR, C_cw},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw},
        /*3 C_cw*/ {C_cw | ERR, B_cw, D_cw, C_cw},

        /*4 B_ccw*/ {A | DOWN, B_ccw, B_ccw | ERR, C_ccw},
        /*5 D_ccw*/ {A, D_ccw | ERR, D_ccw, C_ccw},
        /*6 C_ccw*/ {C_ccw | ERR, B_ccw, D_ccw, C_ccw},
    };

    const uint8_t EncoderBase::stateMachineHalf[7][4]{
        //              00        01         10        11
        /*0 A   */ {A, B_cw, D_ccw, A | ERR},
        /*1 B_cw*/ {A, B_cw, B_cw | ERR, C_cw | UP},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw},
        /*3 C_cw*/ {C_cw | ERR, B_ccw, D_cw, C_cw}, // C_ccw = C_cw

        /*4 B_ccw*/ {A | DOWN, B_ccw, B_ccw | ERR, C_cw},
        /*5 D_ccw*/ {A, B_ccw | ERR, D_ccw, C_cw | DOWN},
        /*6 C_ccw*/ {C_ccw | ERR, C_ccw | ERR, C_ccw | ERR, C_ccw | ERR}, //should never be in this state...
    };

    const uint8_t EncoderBase::stateMachineFull[7][4]{
        //              00        01         10        11
        /*0 A   */ {A, B_cw | UP, D_cw | DOWN, A | ERR},
        /*1 B_cw*/ {A | DOWN, B_cw, B_cw | ERR, C_cw | UP},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw | DOWN},
        /*3 C_cw*/ {C_cw | ERR, B_cw | DOWN, D_cw | UP, C_cw},
    };
} // namespace EncoderTool

// the linker currently (<=td1.54) does not always link in _write
// this is a ugly workaround to fix it for T3.x boards
// T4.x don't show the issue.

#if defined(KINETISK)
extern "C" {
int _write(int file, char* ptr, int len)
{
    ((class Print*)file)->write((uint8_t*)ptr, len);
    return len;
}
}
#endif