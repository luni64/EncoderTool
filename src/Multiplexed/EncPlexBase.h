#pragma once

#include "EncoderBase.h"
#include "config.h"

namespace EncoderTool
{
    template <typename counter_t>
    class EncPlexBase
    {
     public:
#if defined(PLAIN_ENC_CALLBACK)
        using allCallback_t    = stdext::inplace_function<void(uint_fast8_t channel, counter_t value, counter_t delta)>; // all encoder values
        using allBtnCallback_t = stdext::inplace_function<void(uint_fast8_t channel, int_fast8_t state)>;                // all encoder buttons
#else
        using allCallback_t    = void (*)(uint_fast8_t channel, counter_t value, counter_t delta);
        using allBtnCallback_t = void (*)(uint_fast8_t channel, int_fast8_t state);
#endif

        void attachCallback(allCallback_t callback);
        void attachBtnCallback(allBtnCallback_t btnCallback);
        EncoderBase<counter_t>& operator[](size_t idx);

     protected:
        EncPlexBase(unsigned EncoderCount);
        ~EncPlexBase();

        void begin(CountMode mode = CountMode::quarter);
        void begin(allCallback_t, CountMode mode = CountMode::quarter);
        void begin(allCallback_t, allBtnCallback_t, CountMode mode = CountMode::quarter);

        const size_t encoderCount;
        EncoderBase<counter_t>* encoders;

        allCallback_t callback = nullptr;
        allBtnCallback_t btnCallback = nullptr;
        counter_t c;
    };

    template <typename counter_t>
    EncPlexBase<counter_t>::EncPlexBase(unsigned eCnt)
        : encoderCount(eCnt)
    {
        encoders = new EncoderBase<counter_t>[eCnt];
    }

    template <typename counter_t>
    void EncPlexBase<counter_t>::begin(CountMode mode)
    {
        for (unsigned i = 0; i < encoderCount; i++)
        {
            encoders[i].setCountMode(mode);
        }
    }

    template <typename counter_t>
    EncPlexBase<counter_t>::~EncPlexBase()
    {
        delete[] encoders;
    }

    template <typename counter_t>
    EncoderBase<counter_t>& EncPlexBase<counter_t>::operator[](size_t idx)
    {
        return idx < encoderCount ? encoders[idx] : encoders[encoderCount - 1];
    }

    template <typename counter_t>
    void EncPlexBase<counter_t>::attachCallback(allCallback_t _callback)
    {
        callback = _callback;
    }
    template <typename counter_t>
    void EncPlexBase<counter_t>::attachBtnCallback(allBtnCallback_t _btnCallback)
    {
        btnCallback = _btnCallback;
    }
}
