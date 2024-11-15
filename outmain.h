#include "macro.h"

#ifndef OUTMAIN_MARK
    #define OUTMAIN_MARK 0
#endif

#ifdef OUTMAIN_SYNTAX
    #include OUTMAIN_SYNTAX
    #define _OUTMAIN_SYNTAX 0 /* by user */
#endif




#ifndef _OUTMAIN_SYNTAX
    /* detecting compiller */
    #define _OUTMAIN_SYNTAX 1
#endif



#if _OUTMAIN_SYNTAX == 1 /* GCC */
    #ifdef OUTMAIN_BEFORE
        __attribute__((__constructor__)) static void M_JOIN(_omctr,OUTMAIN_MARK)(void){ OUTMAIN_BEFORE; }
    #endif 
    #ifdef OUTMAIN_AFTER
        __attribute__((__destructor__)) static void M_JOIN(_omdtr,OUTMAIN_MARK)(void){ OUTMAIN_AFTER; }
    #endif 
#endif

#if _OUTMAIN_SYNTAX == 2 /* VS */

#endif

#if _OUTMAIN_SYNTAX == 3 /*  */
    #ifdef OUTMAIN_BEFORE
        static void M_JOIN(_omctr,OUTMAIN_MARK)(void){ OUTMAIN_BEFORE; }
        #pragma startup M_JOIN(_omctr,OUTMAIN_MARK)
    #endif 
    #ifdef OUTMAIN_AFTER
        static void M_JOIN(_omdtr,OUTMAIN_MARK)(void){ OUTMAIN_AFTER; }
        #pragma startup M_JOIN(_omdtr,OUTMAIN_MARK)
    #endif 
#endif

#if _OUTMAIN_SYNTAX == 4 /*  */
    #ifdef OUTMAIN_BEFORE
        void M_JOIN(_omctr,OUTMAIN_MARK)(void){
            __asm__ (".section .init \n call " M_STRING(M_JOIN(_omctr,OUTMAIN_MARK)) " \n .section .text\n");
            OUTMAIN_BEFORE;
        }
    #endif
    #ifdef OUTMAIN_AFTER
        void M_JOIN(_omdtr,OUTMAIN_MARK)(void){
            __asm__ (".section .fini \n call " M_STRING(M_JOIN(_omdtr,OUTMAIN_MARK)) " \n .section .text\n");
            OUTMAIN_AFTER;
        }
    #endif 
#endif




#ifdef OUTMAIN_BEFORE
    #undef OUTMAIN_BEFORE
#endif

#ifdef OUTMAIN_AFTER
    #undef OUTMAIN_AFTER
#endif

#ifdef OUTMAIN_MARK
    #undef OUTMAIN_MARK
#endif
