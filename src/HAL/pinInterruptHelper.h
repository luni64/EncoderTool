#pragma once

#include "core_num_interrupt.h"

namespace HAL
{
    template <typename TYPE, void (TYPE::*MEMBER)()>
    class PinInterruptHelper
    {
     public:
        static void attachInterrupt(uint8_t slot, TYPE* object, int mode);
        static void detachInterrupt(uint8_t pin);
        static bool hasInterrupt(uint8_t pin);

     protected:
        template <uint8_t nr>
        static void relay()
        {
            (objects[nr]->*MEMBER)();
        }

        static TYPE* objects[CORE_NUM_INTERRUPT];
    };

    // inline implementation ===========================================================================

    //hasInterrupt ------------------------------------------------------------------------------------
    template <typename TYPE, void (TYPE::*MEMBER)()>
    bool PinInterruptHelper<TYPE, MEMBER>::hasInterrupt(uint8_t pin)
    {
        uint8_t slot = digitalPinToInterrupt(pin);
        return slot < CORE_NUM_INTERRUPT;
    }

    //detachInterrupt ----------------------------------------------------------------------------------
    template <typename TYPE, void (TYPE::*MEMBER)()>
    void PinInterruptHelper<TYPE, MEMBER>::detachInterrupt(uint8_t pin)
    {
        uint8_t slot = digitalPinToInterrupt(pin);
        ::detachInterrupt(slot);
    }

    //attachInterrupt--------------------------------------------------------------------------------------
    template <typename TYPE, void (TYPE::*MEMBER)()>
    void PinInterruptHelper<TYPE, MEMBER>::attachInterrupt(uint8_t pin, TYPE* object, int mode)
    {
        uint8_t slot = digitalPinToInterrupt(pin);
        if (slot <= CORE_NUM_INTERRUPT)
        {
            objects[slot] = object;
            //::attachInterrupt(slot, relay<0>, mode);

            switch (slot)
            {
#if CORE_NUM_INTERRUPT > 0
                case 0:
                    ::attachInterrupt(slot, relay<0>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 1
                case 1:
                    ::attachInterrupt(slot, relay<1>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 2
                case 2:
                    ::attachInterrupt(slot, relay<2>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 3
                case 3:
                    ::attachInterrupt(slot, relay<3>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 4
                case 4:
                    ::attachInterrupt(slot, relay<4>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 5
                case 5:
                    ::attachInterrupt(slot, relay<5>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 6
                case 6:
                    ::attachInterrupt(slot, relay<6>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 7
                case 7:
                    ::attachInterrupt(slot, relay<7>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 8
                case 8:
                    ::attachInterrupt(slot, relay<8>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 9
                case 9:
                    ::attachInterrupt(slot, relay<9>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 10
                case 10:
                    ::attachInterrupt(slot, relay<10>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 11
                case 11:
                    ::attachInterrupt(slot, relay<11>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 12
                case 12:
                    ::attachInterrupt(slot, relay<2>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 13
                case 13:
                    ::attachInterrupt(slot, relay<13>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 14
                case 14:
                    ::attachInterrupt(slot, relay<14>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 15
                case 15:
                    ::attachInterrupt(slot, relay<15>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 16
                case 16:
                    ::attachInterrupt(slot, relay<16>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 17
                case 17:
                    ::attachInterrupt(slot, relay<17>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 18
                case 18:
                    ::attachInterrupt(slot, relay<18>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 19
                case 19:
                    ::attachInterrupt(slot, relay<19>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 20
                case 20:
                    ::attachInterrupt(slot, relay<20>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 21
                case 21:
                    ::attachInterrupt(slot, relay<21>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 22
                case 22:
                    ::attachInterrupt(slot, relay<22>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 23
                case 23:
                    ::attachInterrupt(slot, relay<23>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 24
                case 24:
                    ::attachInterrupt(slot, relay<24>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 25
                case 25:
                    ::attachInterrupt(slot, relay<25>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 26
                case 26:
                    ::attachInterrupt(slot, relay<26>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 27
                case 27:
                    ::attachInterrupt(slot, relay<27>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 28
                case 28:
                    ::attachInterrupt(slot, relay<28>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 29
                case 29:
                    ::attachInterrupt(slot, relay<29>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 30
                case 30:
                    ::attachInterrupt(slot, relay<30>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 31
                case 31:
                    ::attachInterrupt(slot, relay<31>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 32
                case 32:
                    ::attachInterrupt(slot, relay<2>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 33
                case 33:
                    ::attachInterrupt(slot, relay<33>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 34
                case 34:
                    ::attachInterrupt(slot, relay<34>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 35
                case 35:
                    ::attachInterrupt(slot, relay<35>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 36
                case 36:
                    ::attachInterrupt(slot, relay<36>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 37
                case 37:
                    ::attachInterrupt(slot, relay<37>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 38
                case 38:
                    ::attachInterrupt(slot, relay<38>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 39
                case 39:
                    ::attachInterrupt(slot, relay<39>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 40
                case 40:
                    ::attachInterrupt(slot, relay<40>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 41
                case 41:
                    ::attachInterrupt(slot, relay<41>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 42
                case 42:
                    ::attachInterrupt(slot, relay<42>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 43
                case 43:
                    ::attachInterrupt(slot, relay<43>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 44
                case 44:
                    ::attachInterrupt(slot, relay<44>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 45
                case 45:
                    ::attachInterrupt(slot, relay<45>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 46
                case 46:
                    ::attachInterrupt(slot, relay<46>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 47
                case 47:
                    ::attachInterrupt(slot, relay<47>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 48
                case 48:
                    ::attachInterrupt(slot, relay<48>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 49
                case 49:
                    ::attachInterrupt(slot, relay<49>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 50
                case 50:
                    ::attachInterrupt(slot, relay<0>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 51
                case 51:
                    ::attachInterrupt(slot, relay<1>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 52
                case 52:
                    ::attachInterrupt(slot, relay<52>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 53
                case 53:
                    ::attachInterrupt(slot, relay<53>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 54
                case 54:
                    ::attachInterrupt(slot, relay<54>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 55
                case 55:
                    ::attachInterrupt(slot, relay<55>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 56
                case 56:
                    ::attachInterrupt(slot, relay<56>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 57
                case 57:
                    ::attachInterrupt(slot, relay<57>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 58
                case 58:
                    ::attachInterrupt(slot, relay<58>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 59
                case 59:
                    ::attachInterrupt(slot, relay<59>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 60
                case 60:
                    ::attachInterrupt(slot, relay<60>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 61
                case 61:
                    ::attachInterrupt(slot, relay<61>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 62
                case 62:
                    ::attachInterrupt(slot, relay<62>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 63
                case 63:
                    ::attachInterrupt(slot, relay<63>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 64
                case 64:
                    ::attachInterrupt(slot, relay<64>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 65
                case 65:
                    ::attachInterrupt(slot, relay<65>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 66
                case 66:
                    ::attachInterrupt(slot, relay<66>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 67
                case 67:
                    ::attachInterrupt(slot, relay<67>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 68
                case 68:
                    ::attachInterrupt(slot, relay<68>, CHANGE);
                    break;
#endif
#if CORE_NUM_INTERRUPT > 69
                case 69:
                    ::attachInterrupt(slot, relay<69>, CHANGE);
                    break;
#endif
            }
        }
    }

    //--------------------------------------------------------------------------------------------------
    template <typename TYPE, void (TYPE::*MEMBER)()>
    TYPE* PinInterruptHelper<TYPE, MEMBER>::objects[];
}