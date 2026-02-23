#include "../include/jump.h"
#include "run.h"
void handle_jmp(){
  DBG_RUN0("Optimized handle_jmp() \n");
  bad_address(R[RAM[R[$ip]+1]]);
  R[$ip] = R[RAM[R[$ip]+1]];
  return;
} 

void handle_je(){
  DBG_RUN0("Optimized handle_je() \n");
  if(R[RAM[R[$ip]+1]] == R[RAM[R[$ip]+2]]){
    bad_address(R[RAM[R[$ip]+3]]);
    R[$ip] = R[RAM[R[$ip]+3]];
  }
  else{
    R[$ip] +=4;
  }
  return;
}
void handle_jne(){
  DBG_RUN0("Optimized handle_jne() \n");
  if(R[RAM[R[$ip]+1]] != R[RAM[R[$ip]+2]]){
    bad_address(R[RAM[R[$ip]+3]]);
    R[$ip] = R[RAM[R[$ip]+3]];
  }
  else{
    R[$ip] +=4;
  }
  return;
}
void handle_slt(){
  DBG_RUN0("Optimized handle_slt() \n");
  if(R[RAM[R[$ip]+2]] < R[RAM[R[$ip]+3]]){
    R[RAM[R[$ip]+1]] = (u8)0x1;
  }
  else R[RAM[R[$ip]+1]] = (u8)0x0;
  R[$ip] +=4;
  return;
}
void handle_int(){
  DBG_RUN0("Optimized handle_int() \n");
  // handleInt((u1)R[RAM[R[$ip]+1]]);
  R[$ip]+=2;
  return;
}
void handle_nop(){
  DBG_RUN0("Optimized handle_nop() \n");
  R[$ip]++;
  return;
}
