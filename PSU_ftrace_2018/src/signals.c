#define _GNU_SOURCE
#include <sys/ptrace.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include "ftrace.h"

void	get_sigint(int sig)
{
  (void)sig;
  kill(g_pid, SIGKILL);
  unload_elf(&g_bin);
  print_err("Process %d detached\n", g_pid);
  print_err(" <detached ...>\n");
  exit(0);
}
