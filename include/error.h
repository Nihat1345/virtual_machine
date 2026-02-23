#pragma once
#include "common.h"
#include "win32.h"
#include <stdio.h>
#include "exenv.h"

extern FILE * errPtr;
extern char *err_file_name;

void shut_down(u1 code);
#define FATAL_ERROR(); shut_down(SHUT_DOWN_ERROR);
#define FATAL_ERROR1(str); printf(str); shut_down(SHUT_DOWN_ERROR);

#define ERROR_LVL1(str); FATAL_ERROR1(str);
#define ERROR0_LVL2(str); printf(str);
#define ERROR1_LVL2(str,arg1); printf(str,arg1);
#define ERROR2_LVL2(str,arg2); printf(str,arg2);

#define FCLOSE(ptr) {\
  if(ptr != NULL)\
    fclose(ptr);\
  (ptr) = NULL;\
}
