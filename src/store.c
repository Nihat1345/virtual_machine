#include "../include/store.h"
#include "../include/run.h"
void handle_sb(){
  DBG_RUN0("Optimized handle_sb() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  RAM[R[RAM[R[$ip]+2]]] = (s1)R[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}
void handle_sw(){
  DBG_RUN0("Optimized handle_sw() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  *((s2*)&RAM[R[RAM[R[$ip]+2]]]) = (s2)R[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}
void handle_sd(){
  DBG_RUN0("Optimized handle_sd() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  *((s4*)&RAM[R[RAM[R[$ip]+2]]]) = (s4)R[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}
void handle_sq(){
  DBG_RUN0("Optimized handle_sq() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  *((s8*)&RAM[R[RAM[R[$ip]+2]]]) = (s8)R[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}

void handle_sf1(){
  DBG_RUN0("Optimized handle_sf1() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  *((f4*)&RAM[R[RAM[R[$ip]+2]]]) = Rf[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}
void handle_sf2(){
  DBG_RUN0("Optimized handle_sf2() \n");
  bad_address(R[RAM[R[$ip]+2]]);
  *((f8*)&RAM[R[RAM[R[$ip]+2]]]) = Rd[RAM[R[$ip]+1]];
  R[$ip]+=3;
  return ;
}
