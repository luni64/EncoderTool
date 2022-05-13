#ifndef SA_ESP32_h
#define SA_ESP32_h

#ifdef ARDUINO
    #include <Arduino.h>
#else
    #include <stdint.h>
#endif



static __inline__ void SA_iRestore(const  uint32_t *__s)
{
    XTOS_RESTORE_INTLEVEL(*__s);
}

// Note value can be 0-15, 0 = Enable all interrupts, 15 = no interrupts
#define SA_ATOMIC_RESTORESTATE uint32_t _sa_saved              \
    __attribute__((__cleanup__(SA_iRestore))) = XTOS_DISABLE_LOWPRI_INTERRUPTS


/*************** MACRO **********************/
#define ATOMIC()                                            \
for ( SA_ATOMIC_RESTORESTATE, _sa_done =  1;                   \
    _sa_done; _sa_done = 0 )

#endif
