#include "BaseTester.h"
#include <unity.h>

using namespace EncoderTool;

BaseTester EncoderBaseTester;

void SetGetValue()
{
    EncoderBaseTester.begin(CountMode::full);

    EncoderBaseTester.setValue(42);
    TEST_ASSERT_EQUAL_INT(42, EncoderBaseTester.getValue());
}

void CountModeFull()
{
    EncoderBaseTester.begin(CountMode::full);

    TEST_ASSERT_EQUAL(false, EncoderBaseTester.valueChanged());
    EncoderBaseTester.count(10);
    TEST_ASSERT_EQUAL(true, EncoderBaseTester.valueChanged());
    TEST_ASSERT_EQUAL_INT(10, EncoderBaseTester.getValue());

    EncoderBaseTester.count(-10);
    TEST_ASSERT_EQUAL_INT(0, EncoderBaseTester.getValue());
}

void CountModeHalf()
{
    EncoderBaseTester.begin(CountMode::half);

    EncoderBaseTester.count(10);
    TEST_ASSERT_EQUAL_INT(5, EncoderBaseTester.getValue());

    EncoderBaseTester.count(-10);
    TEST_ASSERT_EQUAL_INT(0, EncoderBaseTester.getValue());
}

void CountModeQtr()
{
    EncoderBaseTester.begin(CountMode::quarter);

    EncoderBaseTester.count(8);
    TEST_ASSERT_EQUAL_INT(2, EncoderBaseTester.getValue());

    EncoderBaseTester.count(-10);
    TEST_ASSERT_EQUAL_INT(0, EncoderBaseTester.getValue());
}

void CyclicCounting()
{
    EncoderBaseTester.begin(CountMode::full);
    EncoderBaseTester.setLimits(-10, 10, true);

    EncoderBaseTester.count(11);
    TEST_ASSERT_EQUAL_INT(-10, EncoderBaseTester.getValue());

    EncoderBaseTester.count(-1);
    TEST_ASSERT_EQUAL_INT(10, EncoderBaseTester.getValue());
}

void LimitCounting()
{
    EncoderBaseTester.begin(CountMode::full);
    EncoderBaseTester.setLimits(-8, 10, false);

    EncoderBaseTester.count(100);
    TEST_ASSERT_EQUAL_INT(10, EncoderBaseTester.getValue());

    EncoderBaseTester.count(-20);
    TEST_ASSERT_EQUAL_INT(-8, EncoderBaseTester.getValue());
}

void valueCallbacks()
{
    int v = 0;
    int d = 0;

    EncoderBaseTester.begin(CountMode::full);
    EncoderBaseTester.attachCallback([&v, &d](int value, int delta) {  v = value; d = delta; });

    EncoderBaseTester.count(1);
    TEST_ASSERT_EQUAL(1, v);
    TEST_ASSERT_EQUAL(1, d);

    EncoderBaseTester.count(-1);
    TEST_ASSERT_EQUAL(0, v);
    TEST_ASSERT_EQUAL(-1, d);

    EncoderBaseTester.setValue(0);
    EncoderBaseTester.count(1234);
    TEST_ASSERT_EQUAL(1234, v);
}

void ButtonTesting()
{
    EncoderBaseTester.begin(CountMode::full);

    EncoderBaseTester.pressButton();
    TEST_ASSERT_TRUE(EncoderBaseTester.buttonChanged());
    TEST_ASSERT_FALSE(EncoderBaseTester.buttonChanged()); // buttonChanged should be resetted
    TEST_ASSERT_EQUAL(1, EncoderBaseTester.getButton());

    EncoderBaseTester.releaseButton();
    TEST_ASSERT_TRUE(EncoderBaseTester.buttonChanged());
    TEST_ASSERT_EQUAL(0, EncoderBaseTester.getButton());
}


int main(int argc, char** argv)
{
    while (!Serial) {}
    // delay(1000);

    UNITY_BEGIN();

    RUN_TEST(SetGetValue);
    RUN_TEST(CountModeFull);
    RUN_TEST(CountModeHalf);
    RUN_TEST(CountModeQtr);
    RUN_TEST(CyclicCounting);
    RUN_TEST(LimitCounting);
    RUN_TEST(valueCallbacks);
    RUN_TEST(ButtonTesting);

    UNITY_END();
}

void setUp(void)
{
}

void tearDown(void)
{
    // clean stuff up here
}