#include "../include/shift.h"
#include "../include/run.h"
void handle_sra(){
  DBG_RUN0("Optimized handle_sra():\n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]] >> (s8) (R[RAM[R[$ip]+3]]);
  R[$ip] +=4;
}
void handle_srl(){
  DBG_RUN0("Optimized handle_srl():\n");
  R[RAM[R[$ip]+1]]= R[RAM[R[$ip]+2]] >> R[RAM[R[$ip]+3]];
  R[$ip] +=4;
}

void handle_sl(){
  DBG_RUN0("Optimized handle_sl():\n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]] << R[RAM[R[$ip]+3]];
  R[$ip] +=4;
}
