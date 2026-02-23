#include "load.h"
#include "run.h"
void handle_lbi(){
  DBG_RUN0("Optimized handle_lbi():\n");
  R[RAM[R[$ip]]+1] = (s1)RAM[R[$ip]+2];
  R[$ip] +=3;
  return;
}
void handle_lwi(){
  DBG_RUN0("Optimized handle_lwi():\n");
  R[RAM[R[$ip]]+1] = (s2)*((s2 *)&RAM[R[$ip]+2]);
  R[$ip] +=4;
  return;
}
void handle_ldi(){
  DBG_RUN0("Optimized handle_ldi():\n");
  R[RAM[R[$ip]]+1] = (s4)*((s4 *)&RAM[R[$ip]+2]);
  R[$ip] +=6;
  return;
}
void handle_lqi(){
  DBG_RUN0("Optimized handle_lqi():\n");
  R[RAM[R[$ip]]+1] = (s8)*((s8 *)&RAM[R[$ip]+2]);
  R[$ip] +=10;
  return;
}
void handle_lf1i(){
  DBG_RUN0("Optimized handle_lf1i():\n");
  R[RAM[R[$ip]]+1] = (f4)*((f4 *)&RAM[R[$ip]+2]);
  R[$ip] +=6;
  return;
}

void handle_lf2i(){
  DBG_RUN0("Optimized handle_lf2i():\n");
  R[RAM[R[$ip]]+1] = (f8)*((f8 *)&RAM[R[$ip]+2]);
  R[$ip] +=10;
  return;
}
void handle_lad(){
  DBG_RUN0("Optimized handle_lad():\n");
  R[RAM[R[$ip]]+1] = (u8)*((u8 *)&RAM[R[$ip]+2]);
  bad_address(R[RAM[R[$ip]+1]]);
  R[$ip] +=10;
  return;
}
void handle_lai(){
  DBG_RUN0("Optimized handle_lai():\n");
  R[RAM[R[$ip]]+1] = R[RAM[R[$ip]+2]] +(s8)*((s8 *)&RAM[R[$ip]+3]);
  bad_address(R[RAM[R[$ip]+1]]);
  R[$ip] +=11;
  return;
}
void handle_lb(){
  DBG_RUN0("Optimized handle_lb():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  R[RAM[R[$ip]+1]] = (s8)(*((s1*)&RAM[R[RAM[R[$ip]+2]]])); 
  R[$ip]+=3;
  return;
}
void handle_lw(){
  DBG_RUN0("Optimized handle_lw():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  R[RAM[R[$ip]+1]] = (s8)(*((s2*)&RAM[(u8)R[RAM[R[$ip]+2]]])); 
  R[$ip]+=3;
  return;
}
void handle_ld(){
  DBG_RUN0("Optimized handle_ld():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  R[RAM[R[$ip]+1]] = (s8)(*((s4*)&RAM[(u8)R[RAM[R[$ip]+2]]])); 
  R[$ip]+=3;
  return;
}
void handle_lq(){
  DBG_RUN0("Optimized handle_lq():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  R[RAM[R[$ip]+1]] = (s8)(*((s8*)&RAM[(u8)R[RAM[R[$ip]+2]]])); 
  R[$ip]+=3;
  return;
}
void handle_lf1(){
  DBG_RUN0("Optimized handle_lf1():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  Rf[RAM[R[$ip]+1]] = *((f4*)&RAM[(u8)R[RAM[R[$ip]+2]]]); 
  R[$ip]+=3;
  return;
}

void handle_lf2(){
  DBG_RUN0("Optimized handle_lf2():\n");
  bad_address(R[RAM[R[$ip]+2]]);
  Rf[RAM[R[$ip]+1]] = *((f8*)&RAM[(u8)R[RAM[R[$ip]+2]]]); 
  R[$ip]+=3;
  return;
}





















