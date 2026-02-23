#pragma once 
#define WIN32_LEAN_AND_MEAN
typedef signed char s1;
typedef signed short s2;
typedef signed long s4;
typedef signed long long s8;

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned long u4;
typedef unsigned long long u8;

typedef float f4;
typedef double f8; 


#define PRINT_UREG(rstr,reg) printf("%-6s=%-21llu\n", rstr,reg)
#define PRINT_SREG(rstr,reg) printf("%-6s=%-21lld\n", rstr, reg)
#define PRINT_FREG(rstr,reg) printf("%-6s= %g\n", rstr,(f4)reg)
#define PRINT_DREG(rstr,reg) printf("%-6s= %g\n", rstr,(f8)reg)

#define pu1(arg) printf("%u\n",arg)
#define pu2(arg) printf("%hu\n",arg)
#define pu4(arg) printf("%llu\n", arg)
#define pu8(arg) printf("%llu\n",arg)


#define ps1(arg) printf("%d\n",arg)
#define ps2(arg) printf("%hd\n",arg)
#define ps4(arg) printf("%lld\n", arg)
#define ps8(arg) printf("%lld\n",arg)

#define ru8(arg) scanf("%llu", arg)

#define fpu8(ptr,arg) fprintf(ptr, "%llu\n",arg)
#define fps8(ptr,arg) fprintf(ptr, "%lld\n",arg)


extern u1 fb[8];

#define FORMAT_WORD(arr, start) { \
  fb[0] = arr[start+1];\
  fb[1] = arr[start];\
  arr[start] = fb[0];\
  arr[start+1] = fb[1];\
} 

#define FORMAT_DWORD(arr, start) {\
  fb[0] = arr[start+3];\
  fb[1] = arr[start+2];\
  fb[2] = arr[start+1];\
  fb[3] = arr[start];\
  arr[start]= fb[0];\
  arr[start+1]= fb[1];\
  arr[start+2]= fb[2];\
  arr[start+3]= fb[3];\
}

#define FORMAT_QWORD(arr, start){\
  fb[0] = arr[start+7];\
  fb[1] = arr[start+6];\
  fb[2] = arr[start+5];\
  fb[3] = arr[start+4];\
  fb[4] = arr[start+3];\
  fb[5] = arr[start+2];\
  fb[6] = arr[start+1];\
  fb[7] = arr[start];\
  arr[start]= fb[0];\
  arr[start+1]= fb[1];\
  arr[start+2]= fb[2];\
  arr[start+3]= fb[3];\
  arr[start+4]= fb[4];\
  arr[start+5]= fb[5];\
  arr[start+6]= fb[6];\
  arr[start+7]= fb[7];\
}

u4 get_available_memory();
u4 get_file_size(const char* name);




