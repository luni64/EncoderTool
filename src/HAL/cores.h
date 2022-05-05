#pragma once

// the following definitions where extracted from the board.txt files in the
// package folders of PIO

#if \
defined(ARDUINO_AVR_YUN) || \
defined(ARDUINO_AVR_UNO) || \
defined(ARDUINO_AVR_DUEMILANOVE) || \
defined(ARDUINO_AVR_NANO) || \
defined(ARDUINO_AVR_MEGA2560) || \
defined(ARDUINO_AVR_MEGA2560) || \
defined(ARDUINO_AVR_MEGA) || \
defined(ARDUINO_AVR_ADK) || \
defined(ARDUINO_AVR_LEONARDO) || \
defined(ARDUINO_AVR_LEONARDO_ETH) || \
defined(ARDUINO_AVR_MICRO) || \
defined(ARDUINO_AVR_ESPLORA) || \
defined(ARDUINO_AVR_MINI) || \
defined(ARDUINO_AVR_ETHERNET) || \
defined(ARDUINO_AVR_FIO) || \
defined(ARDUINO_AVR_BT) || \
defined(ARDUINO_AVR_LILYPAD_USB) || \
defined(ARDUINO_AVR_LILYPAD) || \
defined(ARDUINO_AVR_PRO) || \
defined(ARDUINO_AVR_NG) || \
defined(ARDUINO_AVR_ROBOT_CONTROL) || \
defined(ARDUINO_AVR_ROBOT_MOTOR) || \
defined(ARDUINO_AVR_GEMMA) || \
defined(ARDUINO_AVR_CIRCUITPLAY) || \
defined(ARDUINO_AVR_YUNMINI) || \
defined(ARDUINO_AVR_INDUSTRIAL101) || \
defined(ARDUINO_AVR_LININO_ONE) || \
defined(ARDUINO_AVR_UNO_WIFI_DEV_ED)
#define CORE_AVR_ARDUINO

#elif \
defined(ARDUINO_TEENSY41) || \
defined(ARDUINO_TEENSY_MICROMOD) || \
defined(ARDUINO_TEENSY40)
#define CORE_TEENSY__TEENSY4

#elif \
defined(ARDUINO_TEENSY36) || \
defined(ARDUINO_TEENSY35) || \
defined(ARDUINO_TEENSY32) || \
defined(ARDUINO_TEENSY30) || \
defined(ARDUINO_TEENSYLC)
#define CORE_TEENSY__TEENSY3

#elif \
defined(ARDUINO_TEENSY2PP) || \
defined(ARDUINO_TEENSY2)
#define CORE_TEENSY__TEENSY3

#elif \
defined(WIO_TERMINAL) || \
defined(SEEED_FEMTO_M0) || \
defined(SEEED_XIAO_M0) || \
defined(Wio_Lite_MG126) || \
defined(WIO_GPS_BOARD) || \
defined(SEEED_ZERO) || \
defined(SEEED_LORAWAN) || \
defined(GROVE_UI_WIRELESS)
#define CORE_SAMD_SEED__ARDUINO

#elif \
defined(ARDUINO_SAMD_ZERO) || \
defined(ARDUINO_SAMD_MKR1000) || \
defined(ARDUINO_SAMD_MKRZERO) || \
defined(ARDUINO_SAMD_MKRWIFI1010) || \
defined(ARDUINO_SAMD_NANO_33_IOT) || \
defined(ARDUINO_SAMD_MKRFox1200) || \
defined(ARDUINO_SAMD_MKRWAN1300) || \
defined(ARDUINO_SAMD_MKRWAN1310) || \
defined(ARDUINO_SAMD_MKRGSM1400) || \
defined(ARDUINO_SAMD_MKRNB1500) || \
defined(ARDUINO_SAMD_MKRVIDOR4000) || \
defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define CORE_SAMD__ARDUINO

#endif