TARGET_NAME      := 10_FrequencyGenerator
BOARD_ID         := TEENSY32
MCU              := mk20dx256


#******************************************************************************
# Flags and Defines
#******************************************************************************

CORE_BASE        := C:\Arduino\arduino-1.8.12\hardware\teensy\avr\cores\teensy3

FLAGS_CPU   := -mthumb -mcpu=cortex-m4 -fsingle-precision-constant
FLAGS_OPT   := -O2
FLAGS_COM   := -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD
FLAGS_LSP   := 

FLAGS_CPP   := -fno-exceptions -fpermissive -felide-constructors -std=gnu++14 -Wno-error=narrowing -fno-rtti
FLAGS_C     := 
FLAGS_S     := -x assembler-with-cpp
FLAGS_LD    := -Wl,--print-memory-usage,--gc-sections,--relax,--defsym=__rtc_localtime=$(shell powershell [int](Get-Date -UFormat +%s)[0]) -T$(CORE_BASE)/mk20dx256.ld -lstdc++

LIBS        := -larm_cortexM4l_math -lm

DEFINES     := -D__MK20DX256__ -DTEENSYDUINO=151 -DARDUINO_TEENSY32 -DARDUINO=10807
DEFINES     += -DF_CPU=96000000 -DUSB_SERIAL -DLAYOUT_US_ENGLISH

CPP_FLAGS   := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_CPP)
C_FLAGS     := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_C)
S_FLAGS     := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_S)
LD_FLAGS    := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_LSP) $(FLAGS_LD)
AR_FLAGS    := rcs
NM_FLAGS    := --numeric-sort --defined-only --demangle --print-size



