TARGET_NAME      := 10_FrequencyGenerator
BOARD_ID         := TEENSY40
MCU              := imxrt1062


#******************************************************************************
# Flags and Defines
#******************************************************************************
CORE_BASE        := C:\Arduino\arduino-1.8.12\hardware\teensy\avr\cores\teensy4

FLAGS_CPU   := -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16
FLAGS_OPT   := -O2
FLAGS_COM   := -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD
FLAGS_LSP   := 

FLAGS_CPP   := -std=gnu++14 -fno-exceptions -fpermissive -fno-rtti -fno-threadsafe-statics -felide-constructors -Wno-error=narrowing
FLAGS_C     := 
FLAGS_S     := -x assembler-with-cpp
FLAGS_LD    := -Wl,--print-memory-usage,--gc-sections,--relax,--defsym=__rtc_localtime=$(shell powershell [int](Get-Date -UFormat +%s)[0]) -T$(CORE_BASE)/imxrt1062.ld

LIBS        := -larm_cortexM7lfsp_math -lm -lstdc++

DEFINES     := -D__IMXRT1062__ -DTEENSYDUINO=151 -DARDUINO_TEENSY40 -DARDUINO=10807
DEFINES     += -DF_CPU=600000000 -DUSB_SERIAL -DLAYOUT_US_ENGLISH

CPP_FLAGS   := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_CPP)
C_FLAGS     := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_C)
S_FLAGS     := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_COM) $(DEFINES) $(FLAGS_S)
LD_FLAGS    := $(FLAGS_CPU) $(FLAGS_OPT) $(FLAGS_LSP) $(FLAGS_LD)
AR_FLAGS    := rcs
NM_FLAGS    := --numeric-sort --defined-only --demangle --print-size
