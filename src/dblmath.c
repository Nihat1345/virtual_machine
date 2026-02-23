#include "dblmath.h"
#include "run.h"
void handle_dadd(){
  DBG_RUN0("Optimizeed handle_dadd():\n");
  Rd[RAM[R[$ip]+1]]= Rd[RAM[R[$ip]+2]] + Rd[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_dsub(){
  DBG_RUN0("Optimizeed handle_dsub():\n");
  Rd[RAM[R[$ip]+1]]= Rd[RAM[R[$ip]+2]] - Rd[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_dmult(){
  DBG_RUN0("Optimizeed handle_dmult():\n");
  Rd[RAM[R[$ip]+1]]= Rd[RAM[R[$ip]+2]] * Rd[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_ddiv(){
  DBG_RUN0("Optimizeed handle_ddiv():\n");
  Rd[RAM[R[$ip]+1]]= Rd[RAM[R[$ip]+2]] / Rd[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}

void handle_dslt(){
  DBG_RUN0("Optimizeed handle_dslt");
  if(Rd[RAM[R[$ip]+2]] < Rd[RAM[R[$ip]+3]]){
    Rd[RAM[R[$ip]+1]] = 1.0;
  }
  else 
    Rd[RAM[R[$ip]+1]] = 1.0;
  R[$ip]+=4;
  return;
}
