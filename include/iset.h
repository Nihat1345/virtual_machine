#pragma once
// DATA TRANSFERS
#define lbi                  0
#define lwi                  1
#define ldi                  2
#define lqi                  3
#define lf1i                 4
#define lf2i                 5

#define lad                  6
#define lai                  7

#define lb                   8
#define lw                   9
#define ld                  10
#define lq                  11
#define lf1                 12
#define lf2                 13

#define sb                  14
#define sw                  15
#define sd                  16
#define sq                  17
#define sf1                 18
#define sf2                 19

#define pushb               20
#define pushw               21
#define pushd               22
#define pushq               23
#define pushf1              24
#define pushf2              25

#define popb                26
#define popw                27
#define popd                28
#define popq                29
#define popf1               30
#define popf2               31

#define mov                 32
#define movf                33
#define movd                34

//PROGRAM FLOW CONTROL
#define jmp                 35
#define je                  36
#define jne                 37
#define slt                 38
#define intrpt              39
#define di                  40
#define ei                  41
#define hlt                 42
#define nop                 43

//BITWISE
#define and                 44
#define or                  45
#define xor                 46
#define not                 47
#define bt                  48
#define bs                  49

//SHIFTS
#define sra                 50
#define srl                 51 
#define sl                  52

//INTEGER ARITHMETIC
#define add                 53
#define sub                 54
#define mult                55
#define div                 56

//CONVERSION
#define cast_if             57
#define cast_id             58
#define cast_fi             59
#define cast_fd             60
#define cast_di             61
#define cast_df             62

//FLOATING-POINT ARITHMETIC
#define fadd                63
#define fsub                64
#define fmult               65
#define fdiv                66
#define fslt                67

#define dadd                68
#define dsub                69
#define dmult               70
#define ddiv                71
#define dslt                72

#define bad                 -1


extern char *I_SET[73];
