#include "../include/move.h"
#include "run.h"
void handle_mov(){
  DBG_RUN0("Optimized handle_mov() \n");
  R[RAM[R[$ip]+1]] = R[RAM[R[$ip]+2]];
  R[$ip] +=3;
  return ;
}
void handle_movf(){
  DBG_RUN0("Optimized handle_movf() \n");
  Rf[RAM[R[$ip]+1]] = Rf[RAM[R[$ip]+2]];
  R[$ip] +=3;
  return ;
}
void handle_movd(){
  DBG_RUN0("Optimized handle_movd() \n");
  Rd[RAM[R[$ip]+1]] = Rd[RAM[R[$ip]+2]];
  R[$ip] +=3;
  return ;
}
