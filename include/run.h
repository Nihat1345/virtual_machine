#include "error.h"
#include "iset.h"
#include "load.h"
#include "store.h"
#include "bitwise.h"
#include "dblmath.h"
#include "fltmath.h"
#include "intmath.h"
#include "jump.h"
#include "move.h"
#include "pushpop.h"
#include "shift.h"
#include "exenv.h"

#ifdef DEBUG
#define DBG_RUN0(str) printf(str);
#define DBG_RUN1(str, arg) printf(str, arg);
#else 

#define DBG_RUN0(str)
#define DBG_RUN1(str, arg) 
#endif // DEBUG

extern u1 interupt_on;

void run(u1 dbg);
