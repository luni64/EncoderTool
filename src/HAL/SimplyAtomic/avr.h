
/* Copyright (c) 2007 Dean Camera
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

// Source:
// http://www.nongnu.org/avr-libc/user-manual/atomic_8h_source.html

#ifndef SA_AVR_h
#define SA_AVR_h

#ifdef ARDUINO
    #include <Arduino.h>
#else
    #include <stdint.h>
#endif

#include <avr/io.h>
/******************** HELPERS ***********************/
static __inline__ uint8_t SA_iSeiRetVal(void)
{
    sei();
    return 1;
}

static __inline__ uint8_t SA_iCliRetVal(void)
{
    cli();
    return 1;
}
/*
static __inline__ void __iSeiParam(const uint8_t *__s)
{
    sei();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}

static __inline__ void __iCliParam(const uint8_t *__s)
{
    cli();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}
*/
static __inline__ void SA_iRestore(const  uint8_t *__s)
{
    SREG = *__s;
    __asm__ volatile ("" ::: "memory");
}

#define SA_ATOMIC_RESTORESTATE uint8_t _sa_saved                           \
    __attribute__((__cleanup__(SA_iRestore))) = SREG

/******************** MACRO ***********************/

#define ATOMIC()                                                        \
for ( SA_ATOMIC_RESTORESTATE, _sa_done =  SA_iCliRetVal();                  \
    _sa_done; _sa_done = 0 )


#endif
