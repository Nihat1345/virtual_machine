#pragma once
#ifdef DBG_CMDLINE
#define DBG_CMDLINE0(str);                        printf("handle_arguments(): ") printf(str);
#define DBG_CMDLINE1(str,arg1);                   printf("handle_arguments(): ") printf(str,arg1);
#define DBG_CMDLINE2(str,arg1,arg2);              printf("handle_arguments(): ") printf(str,arg1,arg2);
#else 
#define DBG_CMDLINE0(str);                        
#define DBG_CMDLINE1(str,arg1);                   
#define DBG_CMDLINE2(str,arg1,arg2);              
#endif

#include "win32.h"
#include "error.h"
#include "common.h"  
#include <stdlib.h>
#include <string.h>

#define DEF_HEAP                                  64
#define DEF_STACK                                 64
#define MAX_PROGRAM_ARGS                          32

struct Cmdline {
  char* binary_file;
  u8 heap_request;
  u8 stack_request;
  u1 debug;
  u1 ok;
};

struct Program_args{
  char* args[MAX_PROGRAM_ARGS];
  u1 number_of_args;
};

void print_usage();
void bad_heap_size(char *str);
void bad_stack_size(char *str);
void bad_heap_option();
void bad_stack_option();
void bad_option_char(char c);
struct Cmdline handle_arguments(int argc, char** argv);
