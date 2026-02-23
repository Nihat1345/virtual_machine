#include "fltmath.h"
#include "run.h"
void handle_cast_if(){
  DBG_RUN0("Optimized handle_cast_if(): \n");
  R[RAM[R[$ip]+1]] = (s8)Rf[RAM[R[$ip]+2]];
  R[$ip]+=3; return;
}
void handle_cast_id(){
  DBG_RUN0("Optimized handle_cast_id(): \n");
  R[RAM[R[$ip]+1]] = (s8)Rd[RAM[R[$ip]+2]];
  R[$ip]+=3; return;
}
void handle_cast_fi(){
  DBG_RUN0("Optimized handle_cast_fi(): \n");
  Rf[RAM[R[$ip]+1]] = (f4)((s8)R[RAM[R[$ip]+2]]);
  R[$ip]+=3; return;
}
void handle_cast_di(){
  DBG_RUN0("Optimized handle_cast_di(): \n");
  Rd[RAM[R[$ip]+1]] =(f8) ((s8)Rf[RAM[R[$ip]+2]]);
  R[$ip]+=3; return;
}
void handle_cast_df(){
  DBG_RUN0("Optimized handle_cast_df(): \n");
  Rd[RAM[R[$ip]+1]]= (f8)Rf[RAM[R[$ip]+2]];
  R[$ip]+=3; return;
}
void handle_cast_fd(){
  DBG_RUN0("Optimized handle_cast_fd(): \n");
  Rf[RAM[R[$ip]+1]]= (f4)Rd[RAM[R[$ip]+2]];
  R[$ip]+=3; return;
}
void handle_fadd(){
  DBG_RUN0("Optimized handle_fadd():\n");
  Rf[RAM[R[$ip]+1]] = Rf[RAM[R[$ip]+2]] + Rf[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_fsub(){
  DBG_RUN0("Optimized handle_fsub():\n");
  Rf[RAM[R[$ip]+1]] = Rf[RAM[R[$ip]+2]] - Rf[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_fmult(){
  DBG_RUN0("Optimized handle_fmult():\n");
  Rf[RAM[R[$ip]+1]] = Rf[RAM[R[$ip]+2]] * Rf[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_fdiv(){
  DBG_RUN0("Optimized handle_fdiv():\n");
  Rf[RAM[R[$ip]+1]] = Rf[RAM[R[$ip]+2]] / Rf[RAM[R[$ip]+3]];
  R[$ip]+=4;
  return;
}
void handle_fslt(){
  DBG_RUN0("Optimized handle_fslt():\n");
  if(Rf[RAM[R[$ip]+2]] < Rf[RAM[R[$ip]+3]]){
    Rf[RAM[R[$ip]+1]] = 1.0;
  }
  else 
    Rf[RAM[R[$ip]+1]] = 0.0;
  R[$ip]+=4;
  return;
}
