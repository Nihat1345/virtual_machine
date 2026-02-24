#ifdef DBG_MAIN
#define DBG_MAIN0(str)  printf("main(): "); printf(str);
#define DBG_MAIN1(str,arg1) printf("main(): "); printf(str,arg1);
#define DBG_MAIN2(str,arg1,arg2) printf("main(): "); printf(str,arg1,arg2);
#else
#define DBG_MAIN0(str) 
#define DBG_MAIN1(str,arg1) 
#define DBG_MAIN2(str,arg1,arg2)
#endif

#include <stdio.h>
#include "cmdline.h"
#include "win32.h"
#include "run.h"
#include "reformat.h"
#include "init.h"
#include "error.h"
#pragma pack(push,1)
struct HeaderRec {
    u8 file_size;
    u8 sz_sym_tbl;
    u8 sz_str_tbl;
    u8 sz_byte_code;
    u8 bytecode_file_start;
    u8 bytecode_file_end;
    u8 heap_size;
    u8 stack_size;
    u8 ram;
    u2 magic;
};
#pragma pack(pop)

int main1(){
  FILE* f = fopen("test.RUN", "wb");
  if(!f){
    return 1;
  }
  struct HeaderRec hr;
  memset(&hr,0, sizeof(hr));

  hr.magic = 0xFEED;
  hr.sz_byte_code =1;
  fwrite(&hr, sizeof(hr), 1, f);

  unsigned char bytecode[1] = {42};
  fwrite(bytecode, 1, 1, f);

  fclose(f);
  return 0;
}


int main2(int argc, char *argv[]){
  struct Cmdline cl;
  DBG_MAIN0("1) establishing error log\n");
  DBG_MAIN0("2) invoking handle arguments\n");
  cl = handle_arguments(argc,argv);
  if(!cl.ok){
    FATAL_ERROR1("main(): errors occuring during handling arguments\n");
  }
  DBG_MAIN0("3) invoking initialization of virtual machine\n");
  if(!init(cl)){
    FATAL_ERROR1("main(): errors occuring during initialization of the virtual machine\n");
  }
  DBG_MAIN0("4) invoking reformat\n");
  if(!reformat()){
    FATAL_ERROR1("main(): errors occuring during invoking of reformating\n");
  }
  DBG_MAIN0("5) invoking run\n");
  run(cl.debug);
  DBG_MAIN0("virtual machine is shutting down via halt instruction\n");
  shut_down(SHUT_DOWN_OK);
  return 0;
}
