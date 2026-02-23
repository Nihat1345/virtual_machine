#include "bitwise.h"
#include "run.h"
void handle_and(){
  DBG_RUN0("Optimized handle_and()\n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]] & R[RAM[R[$ip]+3]];
  R[$ip] +=4;
  return;
}
void handle_or(){
  DBG_RUN0("Optimized handle_or()\n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]] | R[RAM[R[$ip]+3]];
  R[$ip] +=4;
  return;
}
void handle_xor(){
  DBG_RUN0("Optimized handle_xor()\n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]] ^ R[RAM[R[$ip]+3]];
  R[$ip] +=4;
  return;
}

void handle_not(){
  DBG_RUN0("Optimized handle_not()\n");
  R[RAM[R[$ip]+1]] = !R[RAM[R[$ip]+2]];
  R[$ip] +=3;
  return ;
}


void handle_bt(){
  DBG_RUN0("Optimized handle_bt()\n");
  u8 mask;
  u8 bit;
  bit = R[RAM[R[$ip]+3]];
  if(bit>63){
    ERROR0_LVL2("handle_bt(): index is out of range\n");
    bit = 63;
  }
  mask = (u8)0x1;
  mask <<= bit;
  mask &= (R[RAM[R[$ip]+2]]);
  if(mask) R[RAM[R[$ip]+1]] = 0x1;
  else R[RAM[R[$ip]+1]] = 0x0;
  R[$ip]+=4;
  return;
}

void handle_bs(){
  u8 mask;
  u8 bit;
  DBG_RUN0("handle_bs()\n");
  bit = R[RAM[R[$ip]+2]];
  if(bit>63){
    ERROR0_LVL2("handle_bs(): index is out of bounds\n");
    bit = 63;
  }
  mask = (u8)0x1;
  mask <<= bit;
  R[RAM[R[$ip]+1]] |= mask;
  R[$ip] +=3;
  return ;
}
