#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/traps.h"
#include "kernel/memlayout.h"

void mem(void) {
  void *m1, *m2;
  int pid, ppid;

  printf(1, "mem test\n");
  ppid = getpid();
  if ((pid = fork()) == 0) {
    m1 = 0;
    while ((m2 = malloc(10001)) != 0) {
      *(char **)m2 = m1;
      m1 = m2;
    }
    while (m1) {
      m2 = *(char **)m1;
      //free(m1);
      m1 = m2;
    }
    m1 = malloc(1024 * 20);
    if (m1 == 0) {
      printf(1, "couldn't allocate mem?!!\n");
      kill(ppid);
      exit();
    }
    free(m1);
    printf(1, "mem ok\n");
    exit();
  } else {
    wait();
  }
}
int main(void)
{
    
    mem();
    return 0;
}