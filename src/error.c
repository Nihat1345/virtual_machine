#include "error.h"
#include <stdlib.h>
#include <stdio.h>

char* err_file_name = "";
FILE* errPtr = NULL;

void shut_down(u1 code){
  if(RAM != NULL) {
    free(RAM);
  }
  else printf("shut_down(): no RAM allocated\n");

  if(errPtr != NULL){
    int retval; 
    retval = fprintf(errPtr, "<ERRORS/>\n");
    if(retval < 0){
      printf("shut_down():\n");
      printf("error while writing in file %s \n", err_file_name);
    }
    if(fclose(errPtr)){
      printf("shut_down(): error while closing %s \n", err_file_name);
    }
  }
  exit(code);
  return;
}
