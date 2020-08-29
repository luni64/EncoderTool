#include "EncPlexBase.h"

namespace EncoderTool
{
    EncPlexBase::EncPlexBase(unsigned eCnt, CountMode mode)
        : encoderCount(eCnt)
    {
        encoders = new EncoderBase[eCnt];
        for (unsigned i = 0; i < eCnt; i++)
        {
            encoders[i].setCountMode(mode);
        }
    }

    EncPlexBase::~EncPlexBase()
    {
        delete[] encoders;
    }

    EncoderBase &EncPlexBase::operator[](std::size_t idx)
    {
        return idx < encoderCount ? encoders[idx] : encoders[encoderCount - 1];
    }

    void EncPlexBase::attachCallback(allCallback_t _callback)
    {
        callback = _callback;
    }
}