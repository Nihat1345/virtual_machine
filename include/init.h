#include "win32.h"
#include "exenv.h"
#include "error.h"
#include "cmdline.h"

#define SIZE_HEADER  sizeof(struct HeaderRec)
#define application  0xFEED

#ifdef DBG_INIT
#define DBG_INIT0(str)  printf("main(): "); printf(str);
#define DBG_INIT1(str,arg1) printf("main(): "); printf(str,arg1);
#define DBG_INIT2(str,arg1,arg2) printf("main(): "); printf(str,arg1,arg2);
#else
#define DBG_INIT0(str) 
#define DBG_INIT1(str,arg1) 
#define DBG_INIT2(str,arg1,arg2)
#endif

u1 init(struct Cmdline cl);
