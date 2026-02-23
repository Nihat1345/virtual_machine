#include "win32.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

u4 get_available_memory(){
  if((u4)(sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE) )<=0){
    printf("get_available_memory():this is a son of bitch\n");
    printf("%ld\n", (u4)(sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE) ));
    return -1;
  }
 return (u4)(sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE) );
} 
u1 fb[8] = {0};

u4 get_file_size(const char* name){
  struct stat st;
  if(!(stat(name,&st))){
    return (u4)st.st_size;
  }
  else {
    printf("get_file_size():stat failed %s\n", strerror(errno));
  }
  return 0;
}

