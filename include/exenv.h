#ifndef EXENV_H
#define EXENV_H
#include "win32.h"


extern u1* RAM;
extern u8 R[32];
extern f4 Rf[10];
extern f8 Rd[10];
extern char* R_STR[];
extern char* Rf_STR[];
extern char* Rd_STR[];

#define $ip 0
#define $sp 1
#define $fp 2
#define $be 3

#define $hs 4
#define $he 5

#define $ss 6
#define $top 7

#define $r1 8
#define $r2 9
#define $r3 10
#define $r4 11
#define $r5 12
#define $r6 13
#define $r7 14
#define $r8 15 
#define $r9 16
#define $r10 17
#define $r11 18
#define $r12 19
#define $r13 20
#define $r14 21
#define $r15 22
#define $r16 23
#define $r17 24
#define $r18 25
#define $r19 26
#define $r20 27
#define $r21 28
#define $r22 29
#define $r23 30
#define $r24 31
#define $f1 0
#define $f2 1
#define $f3 2
#define $f4 3
#define $f5 4
#define $f6 5
#define $f7 6
#define $f8 7
#define $f9 8
#define $f10 9
#define $d1 0
#define $d2 1
#define $d3 2
#define $d4 3
#define $d5 4
#define $d6 5
#define $d7 6
#define $d8 7
#define $d9 8
#define $d10 9
#endif
