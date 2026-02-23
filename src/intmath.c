#include "../include/intmath.h"
#include "error.h"
#include "run.h"
void handle_add(){
  DBG_RUN0("Optimized handle_add(): \n");
  R[RAM[R[$ip]+1]] = (s8)(R[RAM[R[$ip]+2]]) + (s8)(R[RAM[R[$ip]+3]]);
  R[$ip]+=4;
  return ;
}
void handle_sub(){
  DBG_RUN0("Optimized handle_sub(): \n");
  R[RAM[R[$ip]+1]] = (s8)(R[RAM[R[$ip]+2]]) - (s8)(R[RAM[R[$ip]+3]]);
  R[$ip]+=4;
  return ;
}
void handle_mult(){
  DBG_RUN0("Optimized handle_mult(): \n");
  R[RAM[R[$ip]+1]] = (s8)(R[RAM[R[$ip]+2]]) * (s8)(R[RAM[R[$ip]+3]]);
  R[$ip]+=4;
  return ;
}
void handle_div(){
  DBG_RUN0("Optimized handle_div(): \n");
  if(R[RAM[R[$ip]+4]] == 0){
    ERROR0_LVL2("Divide by zero \n");
    R[RAM[R[$ip]+1]]= R[RAM[R[$ip]+2]]= 0xffffffffffffffff;
  }
  else {
    R[RAM[R[$ip]+1]]= ((s8) R[RAM[R[$ip]+3]]) / ((s8)R[RAM[R[$ip]+4]]); 
    R[RAM[R[$ip]+2]]= ((s8) R[RAM[R[$ip]+3]]) % ((s8)R[RAM[R[$ip]+4]]); 
  }
  R[$ip] +=5;
  return;
}
