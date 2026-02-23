#include "win32.h"
#include "reformat.h"
#include "run.h"

void bad_flt_reg(u1 arg){
  if(arg > $f10){
    ERROR1_LVL2("bad_flt_reg(): (%d) is not a float register\n",arg);
    FATAL_ERROR();
  }
  return;
}

void bad_address(u8 arg){
  if(arg > R[$top]){
    DBG_RUN0("bad_address(): invalid address literal \n");
    FATAL_ERROR();
  }
  return;
}
void bad_stack(u8 arg){
  if(arg <= R[$he]){
    ERROR0_LVL2("bad_stack(): stack overflow in heap\n");
    FATAL_ERROR();
  }
  else if( arg > R[$top]){
    ERROR0_LVL2("bad_stack(): stack is underflow beyond top\n");
    FATAL_ERROR();
  }
  return ;
}

void bad_int_reg(u1 arg){
  if(arg > $r24){
    ERROR1_LVL2("bad_int_reg(): integer %d is not a integer register\n", arg);
    FATAL_ERROR();
  }
  return;
}
void bad_dbl_reg(u1 arg){
  if(arg > $d10){
    ERROR1_LVL2("bad_dbl_reg(): (%d) is not a double register\n",arg);
    FATAL_ERROR();
  }
  return;
}
void check_address(u1 *arr,u8 cb){
  u8* addr;
  addr = (u8*)&cb;
  if(*addr > R[$top]){
    ERROR0_LVL2("check_address(): addres out of bounds\n");
    FATAL_ERROR();
  }
  return;
}
void check_current_byte(u8 cb, u8 end){
  if(cb >= end){
    ERROR0_LVL2("check_current_byte(): incomplete instructions\n");
    FATAL_ERROR();
  }
  return ;
}
void check_end_current_byte(u8 cb, u8 end){
  if(cb > end){
    ERROR0_LVL2("check_end_current_byte(): incomplete instructions\n");
    FATAL_ERROR();
  }
  return ;
}

u1 reformat(){
  u8 current_byte;
  u8 stop;
  current_byte = 0;
  stop = R[$hs];

  // DBG_FMT0("initiating reformat\n\n"); 
  // DBG_FMT_PU8("starting address ->", current_byte);
  while(current_byte < stop){
    switch(RAM[current_byte]){
      case lbi:{
                 // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);

                 bad_int_reg(RAM[current_byte]);
                 // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);

                 // DBG_FMT1("byte %d\n\n", (s1)RAM[current_byte]);
                 check_end_current_byte(current_byte,stop);
               }break;
      case lwi:{

                 // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);

                 bad_int_reg(RAM[current_byte]);
                 // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                 current_byte++;
                 FORMAT_WORD(RAM,current_byte);
                 check_current_byte(current_byte,stop);
                 
                 // DBG_FMT1("word %hd\n\n", *((s2 *)&RAM[current_byte]));
                 current_byte +=2;
                 check_end_current_byte(current_byte,stop);
               }break;
      case ldi:{
                 // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);
                 
                 bad_int_reg(RAM[current_byte]);
                 // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                 current_byte++;
                 FORMAT_WORD(RAM,current_byte);
                 check_current_byte(current_byte,stop);

                 // DBG_FMT1("double word %ld\n\n", *((s4 *)&RAM[current_byte]));
                 current_byte +=4;
                 check_end_current_byte(current_byte,stop);
               }break;
      case lqi:{

                 // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);
                 
                 bad_int_reg(RAM[current_byte]);
                 // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                 current_byte++;
                 FORMAT_WORD(RAM,current_byte);
                 check_current_byte(current_byte,stop);

//                 DBG_FMT1_PS8("quad word", *((s4 *)&RAM[current_byte]));
                 current_byte +=8;
                 check_end_current_byte(current_byte,stop);
               }break;
      case lf1i:{
                  // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                  current_byte++;
                  check_current_byte(current_byte,stop);

                  bad_flt_reg(RAM[current_byte]);
 //                 DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                  current_byte++;
                  FORMAT_WORD(RAM,current_byte);
                  check_current_byte(current_byte,stop);

  //                DBG_FMT1("float %g\n\n", *((f4 *)&RAM[current_byte]));
                  current_byte +=4;
                  check_end_current_byte(current_byte,stop);
                }break;
      case lf2i:{
                  // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                  current_byte++;
                  check_current_byte(current_byte,stop);

                  bad_flt_reg(RAM[current_byte]);
  //                DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                  current_byte++;

                  FORMAT_WORD(RAM,current_byte);
                  check_current_byte(current_byte,stop);
                  // DBG_FMT1("float %g\n\n", *((f8 *)&RAM[current_byte]));
                  current_byte +=8;
                  check_end_current_byte(current_byte,stop);

                }break;
      case lai:{

                 // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                 current_byte++;
                 check_current_byte(current_byte,stop);

                 bad_int_reg(RAM[current_byte]);
                 // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                 current_byte++;

                 FORMAT_QWORD(RAM,current_byte);
                 check_current_byte(current_byte,stop);
                 // DBG_FMT1_PS8("quad word", *((s8 *)&RAM[current_byte]));
                 current_byte +=8;
                 check_end_current_byte(current_byte,stop);
               }break;
      case lb:
      case lw:
      case ld:
      case lq:
      case sb: 
      case sw:
      case sd:
      case sq:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
              }break;
      case lf1:
      case lf2:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);
                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", R_str[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);
                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
               }break;
      case pushb:
      case pushw:
      case pushd:
      case pushq:
      case popb:
      case popw:
      case popd:
      case popq:
      case jmp:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
               }break;
      case pushf1:
      case popf1:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
                }break;
      case pushf2:
      case popf2:{

                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
                 }break;
      case movf:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);

                }break;
      case movd:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);


                }break;
      case mov:
      case not:
      case bs:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
              }break;
      case je:
      case jne:
      case slt:
      case and:
      case or:
      case xor:
      case bt:
      case sra: 
      case srl:
      case sl:
      case add:
      case sub:
      case mult:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);

                }break;
      case intrpt:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                // DBG_FMT1("vector %d\n\n", RAM[current_byte]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
               }break;
      case ei:
      case di:
      case hlt:
      case nop:{
                 
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_end_current_byte(current_byte,stop);
               }break;
      case div:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);


                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);


                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);

               }break;
      case cast_if:{

                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
                   }break;
      case cast_id:{

                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);

                   }break;
      case cast_fi:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);


                   }break;
      case cast_di:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_int_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);


                  }break;
      case cast_fd:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);


                   }break;
      case cast_df:{

                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);



                   }break;
      case fadd:
      case fsub:
      case fmult:
      case fdiv:
      case fslt:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_flt_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);
                }break;
      case dadd:
      case dsub: 
      case dmult:
      case ddiv:
      case dslt:{
                // DBG_FMT1("opcode %s\n", I_set[RAM[current_byte]]);
                current_byte++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_current_byte(current_byte,stop);

                bad_dbl_reg(RAM[current_byte]);
                // DBG_FMT1("operand %s\n", *R_str[RAM[current_byte]]);
                current_byte ++;
                check_end_current_byte(current_byte,stop);

                }break;
      default:{
                ERROR1_LVL2("reformat(): bad opcode %d \n", RAM[current_byte]);
                return (FALSE);
              }
    }
  }
  // DBG_FMT0("reformatting completed\n");
  return (TRUE);

}

















