#include "../include/cmdline.h"
struct Program_args program_args;

void print_usage(){
  printf("\n \t VM [options] file.RUN [arguments] \n\n");
  printf("\t virtual machien options : \n\n");
  printf("\t -h=XXX \t memory to allocate for heap in KB\n\n");
  printf("\t -s=XXX \t memory to allocate for stack in KB\n\n");
  printf("\t -d\t enable to debug\n\n");
  printf("\t -? \t print help\n\n");
  return ;
}
void bad_heap_size(char *str){
  ERROR1_LVL2("bad_heap_size(): bad heap request %s\n", str);
  ERROR0_LVL2("bad_heap_size(): require a positive integer\n");
  return;
}
void bad_stack_size(char *str){
  ERROR1_LVL2("bad_stack_size(): bad stack request (%s)\n", str);
  ERROR0_LVL2("bad_stack_size(): require a positive integer\n");
  return;
}
void bad_heap_option(){
  ERROR0_LVL2("bad_heap_option(): incorrect '\' -h'\' switch \n");
  return;
}
void bad_stack_option(){
  ERROR0_LVL2("bad_stack_option(): incorrect '\' -s'\' switch \n");
  return;
}
void bad_option_char(char c){
  ERROR1_LVL2("bad_option_char(): - %c is invalid \n", c);
  return;
}


struct Cmdline handle_arguments(int argc, char** argv){
  struct Cmdline cmdline;
  int i;
  int name_len;

  cmdline.binary_file = NULL;
  cmdline.heap_request = DEF_HEAP;
  cmdline.stack_request = DEF_STACK;
  cmdline.ok = TRUE;
  cmdline.debug = FALSE;
  program_args.number_of_args = 0;
  if(argc < 2){
    ERROR0_LVL2("handle_arguments(): no arguments \n");
    print_usage();
    cmdline.ok = FALSE;
    return (cmdline);
  }
  else if(argc > MAX_PROGRAM_ARGS){

    ERROR0_LVL2("handle_arguments(): maximum arguments limit is reached limit is 32 argument \n");
    print_usage();
    cmdline.ok = FALSE;
    return (cmdline);

  }
  i = 1;
  cmdline.binary_file = argv[i];
  while(i < argc && argv[i][0] == '-'){
    switch (argv[i][1]) {
      case 'h':
      case 'H':{
                 if(argv[i][2] == '='){
                   char *stop;
                   s4 temp;
                   temp = strtol(&argv[i][3], &stop,10);
                   if(temp<= 0){
                     bad_heap_size(argv[i]);
                     print_usage();
                     cmdline.ok = FALSE;
                     return (cmdline);
                   }
                   cmdline.heap_request = (u8) temp;
                   DBG_CMDLINE0("heap size is set\n");
                   i++;
                 }
                 else {
                   bad_heap_option();
                   print_usage();
                   cmdline.ok = FALSE;
                   return (cmdline);
                 }
               }break;

      case 's':
      case 'S':{
                 if(argv[i][2] == '='){
                   char *stop;
                   s4 temp;
                   temp = strtol(&argv[i][3], &stop,10);
                   if(temp<= 0){
                     bad_heap_size(argv[i]);
                     print_usage();
                     cmdline.ok = FALSE;
                     return (cmdline);
                   }
                   cmdline.stack_request = (u8) temp;
                   DBG_CMDLINE0("stack size is set\n");
                   i++;
                 }
                 else {
                   bad_stack_option();
                   print_usage();
                   cmdline.ok = FALSE;
                   return (cmdline);
                 }
               }break;
      case '?':{
                 print_usage();
                 cmdline.ok = FALSE;
                 return (cmdline);
               }break;
      case 'd':{
                 cmdline.debug = TRUE;
                 DBG_CMDLINE0("debug switch it toggled \n");
                i++;
               }break;

      default:{
                bad_option_char(argv[i][1]);
                print_usage();
                cmdline.ok = FALSE;
                return (cmdline);
              }
    }
    name_len = strlen(argv[i]);
    if(name_len < 4){
      ERROR0_LVL2("handle_arguments(): no .RUN suffix\n");
      printf("%d\n", name_len);
      print_usage();
      cmdline.ok = FALSE;
      return (cmdline);
    }
    else if(argv[i][name_len-4] == '.' &&
            argv[i][name_len-3] == 'R' &&
            argv[i][name_len-2] == 'U' &&
            argv[i][name_len-1] == 'N'){
      cmdline.binary_file = argv[i];
      i++;
    }
    else {
      ERROR0_LVL2("handle_arguments(): no .RUN suffix\n");
      print_usage();
      cmdline.ok = FALSE;
      return (cmdline); } while(i < argc){
      if(program_args.number_of_args < MAX_PROGRAM_ARGS){
        program_args.args[program_args.number_of_args] = argv[i];
        program_args.number_of_args++;
      }
      i++;
    }

  }
    DBG_CMDLINE0("Command line summarize ---------\n");
    DBG_CMDLINE1("\t heap_request= %lu", cmdline.heap_request);
    DBG_CMDLINE1("\t stack_request= %lu", cmdline.stack_request);
    if(cmdline.debug == TRUE){
      DBG_CMDLINE0("\t debugging is enabled\n");
    }
    else 
      DBG_CMDLINE0("\t debugging is disabled\n");

    DBG_CMDLINE1("\t file to load is %s", cmdline.binary_file);
    for(i =0; i<program_args.number_of_args; i++){
      DBG_CMDLINE2("\t arg[%d] = %s\n",i, program_args.args[i]);
    }
    return (cmdline);
}


















