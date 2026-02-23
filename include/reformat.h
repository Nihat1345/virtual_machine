#pragma once
#include "error.h"
#include "win32.h"
#include "exenv.h"
#include "iset.h"

void bad_flt_reg(u1 arg);
void bad_stack(u8 arg);
void bad_int_reg(u1 arg);
void bad_dbl_reg(u1 arg);
void check_address(u1 *arr,u8 cb);
void check_current_byte(u8 cb, u8 end);
void check_end_current_byte(u8 cb, u8 end);
void bad_address(u8 arg);
u1 reformat();
