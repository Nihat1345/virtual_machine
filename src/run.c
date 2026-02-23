#include "run.h"
#include "error.h"
#include "load.h"

u1 interupt_on = FALSE;

void run(u1 dbg){
  u2 tick;
  u8 start_debug_instr;
  tick = 0;
  // debug = dbg;
  interupt_on = TRUE;
  DBG_RUN0("initiating bytecode execution\n");
  while(RAM[R[$ip]] != hlt){
    // if(debug) read_dbg_cmd();
    start_debug_instr = (u8)R[$ip];
    switch(RAM[R[$ip]]){
      case lbi: {handle_lbi();} break;
      case lwi: {handle_lwi();} break;
      case ldi: {handle_ldi();} break;
      case lqi: {handle_lqi();} break;
      case lf1i: {handle_lf1i();} break;
      case lf2i: {handle_lf2i();} break;
      case lad: {handle_lad();} break;
      case lai: {handle_lai();} break;
      case lb: {handle_lb();} break;
      case lw: {handle_lw();} break;
      case ld: {handle_ld();} break;
      case lq: {handle_lq();} break;
      case lf1: {handle_lf1();} break;
      case lf2: {handle_lf2();} break;
      case sb: {handle_sb();} break;
      case sw: {handle_sw();} break;
      case sd: {handle_sd();} break;
      case sq: {handle_sq();} break;
      case sf1: {handle_sf1();} break;
      case sf2: {handle_sf2();} break;
      case pushb: {handle_pushb();} break;
      case pushw: {handle_pushw();} break;
      case pushd: {handle_pushd();} break;
      case pushq: {handle_pushq();} break;
      case pushf1: {handle_pushf1();} break;
      case pushf2: {handle_pushf2();} break;
      case popb: {handle_popb();} break;
      case popw: {handle_popw();} break;
      case popd: {handle_popd();} break;
      case popq: {handle_popq();} break;
      case popf1: {handle_popf1();} break;
      case popf2: {handle_popf2();} break;
      case mov: {handle_mov();} break;
      case movf: {handle_movf();} break;
      case movd: {handle_movd();} break;
      case jmp: {handle_jmp();} break;
      case je: {handle_je();} break;
      case jne: {handle_jne();} break;
      case slt: {handle_slt();} break;
      case intrpt: {handle_int();} break;
                   // case di: {handle_di();} break;
                   // case ei: {handle_ei();} break;
      case nop: {handle_nop();} break;
      case and: {handle_and();} break;
      case or: {handle_or();} break;
      case not: {handle_not();} break;
      case xor: {handle_xor();} break;
      case bt: {handle_bt();} break;
      case bs: {handle_bs();} break;
      case sra: {handle_sra();} break;
      case sl: {handle_sl();} break;
      case add: {handle_add();} break;
      case sub: {handle_sub();} break;
      case mult: {handle_mult();} break;
      case div: {handle_div();} break;
      case cast_if: {handle_cast_if();} break;
      case cast_id: {handle_cast_id();} break;
      case cast_fd: {handle_cast_fd();} break;
      case cast_fi: {handle_cast_fi();} break;
      case cast_di: {handle_cast_di();} break;
      case cast_df: {handle_cast_df();} break;
      case fadd: {handle_fadd();} break;
      case fsub: {handle_fsub();} break;
      case fmult: {handle_fmult();} break;
      case fdiv: {handle_fdiv();} break;
      case dadd: {handle_dadd();} break;
      case dsub: {handle_dsub();} break;
      case dmult: {handle_dmult();} break;
      case ddiv: {handle_ddiv();} break;
      case fslt: {handle_fslt();} break;
      case dslt: {handle_dslt();} break;
      default:{
                ERROR_LVL1("run(): fatal error\n");
              }break;
    }
  }
}
