#include "exenv.h"
#include <stdio.h>

u1* RAM = NULL;
u8 R[32] = {0};
f4 Rf[10] = {0};
f8 Rd[10] = {0};


char* R_STR[] = {
"$ip","$sp","$fp","$be","$hs","$he","$ss","$top","$r1","$r2","$r3","$r4","$r5","$r6","$r7","$r8","$r9","$r10","$r11","$r12","$r13","$r14","$r15","$r16","$r17","$r18","$r19","$r20","$r21","$r22","$r23","$r24"
};

char* Rf_STR[] ={
"$f1","$f2","$f3","$f4","$f5","$f6","$f7","$f8","$f9","$f10"
};


char* Rd_STR[] ={
"$d1","$d2","$d3","$d4","$d5","$d6","$d7","$d8","$d9","$d10"
};

void print_memory_section(u8 address , u8 bytes){
  u8 index;
  for(index = address; index<address+bytes; index++){
    if(index > R[$top]){
      printf("print_memory_section(): address\n");
      pu8(index);
      printf(" out of bounds\n");
    }
  }
  return;
}


void print_basic_registers(){
  printf("BASIC REGISTERS --------------\n");
  PRINT_UREG(R_STR[$ip], R[$ip]);
  PRINT_UREG(R_STR[$sp], R[$sp]);
  PRINT_UREG(R_STR[$fp], R[$fp]);
  PRINT_UREG(R_STR[$be], R[$be]);
  PRINT_UREG(R_STR[$hs], R[$hs]);
  PRINT_UREG(R_STR[$he], R[$he]);
  PRINT_UREG(R_STR[$ss], R[$ss]);
  PRINT_UREG(R_STR[$top], R[$top]);
  printf("------------------------------\n");
  return;
}

void print_general_registers(){

  printf("GENERAL REGISTERS ------------\n");
  PRINT_SREG(R_STR[$r1], R[$r1]);
  PRINT_SREG(R_STR[$r2], R[$r2]);
  PRINT_SREG(R_STR[$r3], R[$r3]);
  PRINT_SREG(R_STR[$r4], R[$r4]);
  PRINT_SREG(R_STR[$r5], R[$r5]);
  PRINT_SREG(R_STR[$r6], R[$r6]);
  PRINT_SREG(R_STR[$r7], R[$r7]);
  PRINT_SREG(R_STR[$r8], R[$r8]);
  PRINT_SREG(R_STR[$r9], R[$r9]);
  PRINT_SREG(R_STR[$r10], R[$r10]);
  PRINT_SREG(R_STR[$r11], R[$r11]);
  PRINT_SREG(R_STR[$r12], R[$r12]);
  PRINT_SREG(R_STR[$r13], R[$r13]);
  PRINT_SREG(R_STR[$r14], R[$r14]);
  PRINT_SREG(R_STR[$r15], R[$r15]);
  PRINT_SREG(R_STR[$r16], R[$r16]);
  PRINT_SREG(R_STR[$r17], R[$r17]);
  PRINT_SREG(R_STR[$r18], R[$r18]);
  PRINT_SREG(R_STR[$r19], R[$r19]);
  PRINT_SREG(R_STR[$r20], R[$r20]);
  PRINT_SREG(R_STR[$r21], R[$r21]);
  PRINT_SREG(R_STR[$r22], R[$r22]);
  PRINT_SREG(R_STR[$r23], R[$r23]);
  PRINT_SREG(R_STR[$r24], R[$r24]);
  printf("------------------------------\n");
  return;
}

void print_float_registers(){
  printf("FLOATING POINT REGISTERS -----\n");
  PRINT_FREG(Rd_STR[$f1], Rd[$f1]);
  PRINT_FREG(Rd_STR[$f2], Rd[$f2]);
  PRINT_FREG(Rd_STR[$f3], Rd[$f3]);
  PRINT_FREG(Rd_STR[$f4], Rd[$f4]);
  PRINT_FREG(Rd_STR[$f5], Rd[$f5]);
  PRINT_FREG(Rd_STR[$f6], Rd[$f6]);
  PRINT_FREG(Rd_STR[$f7], Rd[$f7]);
  PRINT_FREG(Rd_STR[$f8], Rd[$f8]);
  PRINT_FREG(Rd_STR[$f9], Rd[$f9]);
  PRINT_FREG(Rd_STR[$f10], Rd[$f10]);
  printf("------------------------------\n");
  return;
}

void print_double_registers(){
  printf("DOUBLE REGISTERS -------------\n");
  PRINT_DREG(Rf_STR[$d1], Rf[$d1]);
  PRINT_DREG(Rf_STR[$d2], Rf[$d2]);
  PRINT_DREG(Rf_STR[$d3], Rf[$d3]);
  PRINT_DREG(Rf_STR[$d4], Rf[$d4]);
  PRINT_DREG(Rf_STR[$d5], Rf[$d5]);
  PRINT_DREG(Rf_STR[$d6], Rf[$d6]);
  PRINT_DREG(Rf_STR[$d7], Rf[$d7]);
  PRINT_DREG(Rf_STR[$d8], Rf[$d8]);
  PRINT_DREG(Rf_STR[$d9], Rf[$d9]);
  PRINT_DREG(Rf_STR[$d10], Rf[$d10]);
  printf("------------------------------\n");
  return;
}
