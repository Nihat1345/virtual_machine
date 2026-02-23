#include "init.h"
#include <stdlib.h>
#pragma pack(push,1)
struct HeaderRec {
    u8 file_size;
    u8 sz_sym_tbl;
    u8 sz_str_tbl;
    u8 sz_byte_code;
    u8 bytecode_file_start;
    u8 bytecode_file_end;
    u8 heap_size;
    u8 stack_size;
    u8 ram;
    u2 magic;
};
#pragma pack(pop)
u1 init(struct Cmdline cl){
  u8 file_size;
  FILE *fptr;

  struct HeaderRec hr;
  u8 bytecode_start;
  u8 bytecode_end;

  u8 exec_bytes;
  u8 total_bytes;
  u8 free_bytes;

  u8 index;
  u8 i;
  int read_byte;

  file_size = get_file_size(cl.binary_file);
  if(file_size == 0){
    ERROR0_LVL2("init_vm(): executable has zero size\n");
    return (FALSE);
  }
  if((fptr = fopen(cl.binary_file, "rb")) == NULL){
    ERROR1_LVL2("init_vm(): cannot open file %s", cl.binary_file);
    return (FALSE);
  }
  if(fread(&hr, sizeof(struct HeaderRec), 1, fptr) != 1){
    ERROR0_LVL2("init_vm(): failed to read header\n ");
    fclose(fptr);
    return FALSE;
  }
  DBG_INIT0("populate symbol table --------\n");
 // populate_debug_data(&hr,&debug_data, fptr);
//  PRINT_SYM_TABLE();
  DBG_INIT0("end symbol table -------------\n");
  DBG_INIT0("finished reading header and symbol table\n");
  DBG_INIT1("magic number %X\n", hr.magic);
  DBG_INIT1("symbol table size %llu\n", hr.sz_sym_tbl);
  DBG_INIT1("symbol string size %llu\n", hr.sz_str_tbl);
  DBG_INIT1("byte code table size", hr.sz_byte_code);

  // if(hr.magic != (u2)application){
  //   ERROR0_LVL2("init_vm(): file not executable\n");
  //   FCLOSE(fptr);
  //   return (FALSE);
  // }

  if(hr.sz_byte_code == 0){
    ERROR1_LVL2("init_vm(): no byte code in %s\n", cl.binary_file);
    FCLOSE(fptr);
    return (FALSE);
  }
  bytecode_start = SIZE_HEADER + hr.sz_sym_tbl + hr.sz_str_tbl;
  bytecode_end = (bytecode_start+ hr.sz_byte_code)-1;
  DBG_INIT1("bytecode_start in file = %lu\n", bytecode_start);
  DBG_INIT1("bytecode_end in file = %lu\n", bytecode_end);

  exec_bytes = (bytecode_end - bytecode_start) +1;

  total_bytes = exec_bytes + (cl.heap_request*1024ULL)+ (cl.stack_request*1024ULL);
  free_bytes = get_available_memory();
  printf("%llu\n", total_bytes);
  printf("%llu\n", free_bytes);

  if(total_bytes > free_bytes){
    ERROR0_LVL2("init_vm(): not enough memory to init run time\n");
    FCLOSE(fptr);
    return (FALSE);
  }

  DBG_INIT1("availabe physical RAM = %lu\n", free_bytes);
  DBG_INIT1("file size = %lu\n", file_size);
  DBG_INIT1("heap bytes = %lu\n", cl.heap_request*1024);
  DBG_INIT1("stack bytes = %lu\n", cl.stack_request*1024);
  DBG_INIT1("total required bytes = %lu\n", total_bytes);

  printf("allocating %llu bytes \n", total_bytes);

  RAM = (u1*)malloc(total_bytes);

  DBG_INIT0("setting up registers\n");
  R[$ip] = 0;
  R[$sp] = total_bytes-1;
  R[$fp] = 0;
  R[$be] = exec_bytes-1;

  R[$hs] = exec_bytes;
  R[$he] = exec_bytes+(cl.heap_request*1024)-1;

  R[$ss] = exec_bytes + (cl.heap_request*1024);
  R[$top] = total_bytes-1;
  struct HeaderRec app_meta_data;

  app_meta_data.file_size = file_size;
  app_meta_data.sz_sym_tbl = hr.sz_sym_tbl;
  app_meta_data.sz_str_tbl = hr.sz_str_tbl;
  app_meta_data.sz_byte_code = hr.sz_byte_code;
  app_meta_data.bytecode_file_start = bytecode_start;
  app_meta_data.bytecode_file_end = bytecode_end;
  app_meta_data.heap_size = cl.heap_request*1024;
  app_meta_data.stack_size = cl.stack_request*1024;
  app_meta_data.ram = total_bytes;

  rewind(fptr);

  if(fseek(fptr, (u4)bytecode_start, SEEK_SET)){
    ERROR0_LVL2("init_vm(): could not find the start of the file");
    return (FALSE);
  }
  i = 0;
  for(index = bytecode_start; index <= bytecode_end; index++){
    read_byte = fgetc(fptr);
    if(read_byte == EOF){
      ERROR0_LVL2("init_vm(): error reading byte code\n");
      FCLOSE(fptr);
      return (FALSE);
    }
    RAM[i] = (u1)read_byte;
    i++;
  }
  FCLOSE(fptr);
  return (TRUE);
}












