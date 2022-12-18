#pragma once
#include "EncoderTool.h"

class BaseTester : public EncoderTool::EncoderBase<int>
{
 public:
    void begin(EncoderTool::CountMode mode)
    {
        curBin = 0b00;
        EncoderBase::setCountMode(mode);
        EncoderBase::begin(0, 0);
        EncoderBase::setValue(0);
        EncoderBase::setLimits(1,-1); //disable limits
    }

    void count(int n)
    {
        for (int i = 0; i < abs(n); i++)
        {
            n > 0 ? grayUp() : grayDown();
            update(msb, lsb);
            // Serial.printf("%d %d\n", msb, lsb);
        }
    }

    void pressButton()
    {
        for (int i = 0; i < 10; i++)
        {
            update(msb, lsb, 1);
            delay(10);
        }
    }

    void releaseButton()
    {
        for (int i = 0; i < 10; i++)
        {
            update(msb, lsb, 0);
            delay(10);
        }
    }

 protected:
    int curBin;
    int msb, lsb;

    void bin2Gray()
    {
        msb = curBin >> 1;
        lsb = msb ^ (curBin & 1);
    }

    void grayUp()
    {
        curBin++;
        curBin &= 0b11;
        bin2Gray();
    }

    void grayDown()
    {
        curBin--;
        curBin &= 0b11;
        bin2Gray();
    }
};