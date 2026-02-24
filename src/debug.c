#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <ucontext.h>

#define REG_RFLAGS 17

void trap_handler(int sig, siginfo_t *info , void *context){
  ucontext_t *uc = (ucontext_t*)context;
  uc-> uc_mcontext.gregs[REG_RFLAGS] &= ~(1<<8);
  printf("sigtrap caught : single-step simulation\n");
}

void install_handler(){
  struct sigaction sa;
  memset(&sa,0, sizeof(sa));
  sa.sa_sigaction = trap_handler;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGTRAP, &sa,NULL);
}

void enable_tf(){
  unsigned long flags;
  asm volatile("pushfq; pop %0": "=r"(flags));
  flags |= 1<<8;
  asm volatile("push %0; popfq":  "=r"(flags));
}

int main(){
  install_handler();
  enable_tf();
  printf("About to single-step ....\n");
  int a = 1+2;
  printf("After single-step , program continues normally ...\n");


}
