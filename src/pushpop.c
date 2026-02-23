#include "../include/pushpop.h"
#include "../include/run.h"
void handle_pushb(){
  DBG_RUN0("optimized handle_pushb() \n");
  R[$sp]--;
  bad_stack(R[$sp]);
  RAM[R[$sp]] =(s1)(R[RAM[R[$ip]+1]]);
  R[$ip] +=2;
  return;
}
void handle_pushw(){
  DBG_RUN0("optimized handle_pushw() \n");
  R[$sp]-=2;
  bad_stack(R[$sp]);
  *((s2*)&RAM[R[$sp]]) =(s2)(R[RAM[R[$ip]+1]]);
  R[$ip] +=2;
  return;
}

void handle_pushd(){
  DBG_RUN0("optimized handle_pushd() \n");
  R[$sp]-=4;
  bad_stack(R[$sp]);
  *((s4*)&RAM[R[$sp]]) =(s4)(R[RAM[R[$ip]+1]]);
  R[$ip] +=2;
  return;
}

void handle_pushq(){
  DBG_RUN0("optimized handle_pushq() \n");
  R[$sp]-=8;
  bad_stack(R[$sp]);
  *((s4*)&RAM[R[$sp]]) =(s4)(R[RAM[R[$ip]+1]]);
  R[$ip] +=2;
  return;
}

void handle_pushf1(){
  DBG_RUN0("Optimized handle_pushf1() \n");
  R[$sp]-=4;
  bad_stack(R[$sp]);
  *((f4*)&RAM[R[$sp]]) = Rf[RAM[R[$ip]+1]];
  R[$ip] +=2;
  return;
}
void handle_pushf2(){
  DBG_RUN0("Optimized handle_pushf2() \n");
  R[$sp]-=8;
  bad_stack(R[$sp]);
  *((f4*)&RAM[R[$sp]]) = Rd[RAM[R[$ip]+1]];
  R[$ip] +=2;
  return;
}

void handle_popb(){
  DBG_RUN0("Optimized handle_popb() \n");
  R[RAM[R[$ip]+1]] = (s8)*((s1*)&RAM[R[$sp]]);
  R[$sp]++;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}

void handle_popw(){
  DBG_RUN0("Optimized handle_popw() \n");
  R[RAM[R[$ip]+1]] = (s8)*((s2*)&RAM[R[$sp]]);
  R[$sp]+=2;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}
void handle_popd(){
  DBG_RUN0("Optimized handle_popd() \n");
  R[RAM[R[$ip]+1]] = (s8)*((s4*)&RAM[R[$sp]]);
  R[$sp]+=4;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}
void handle_popq(){
  DBG_RUN0("Optimized handle_popq() \n");
  R[RAM[R[$ip]+1]] = (s8)*((s8*)&RAM[R[$sp]]);
  R[$sp]+=8;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}

void handle_popf1(){
  DBG_RUN0("Optimized handle_popf1() \n");
  Rf[RAM[R[$ip]+1]] = (f4)*((f4*)&RAM[R[$sp]]);
  R[$sp]+=4;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}

void handle_popf2(){
  DBG_RUN0("Optimized handle_popf2() \n");
  Rd[RAM[R[$ip]+1]] = (f8) *((f8*)&RAM[R[$sp]]);
  R[$sp]+=4;
  bad_stack(R[$sp]);
  R[$ip] +=2;
  return;
}











