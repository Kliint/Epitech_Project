#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "ftrace.h"
#include "signals.h"

char	*signal_name(int signo)
{
  int	i;

  i = -1;
  while (g_signals[++i].nbr != -1)
    if (g_signals[i].nbr == signo)
      return (g_signals[i].name);
  return (SIGNAL_UNKN);
}

int	aff_end_signal(int status)
{
  if (WIFEXITED(status))
    return (printf("+++ exited with %d +++\n", WEXITSTATUS(status)), 0);
  else if (WIFSIGNALED(status))
    return (printf(SIGNAL_RCV_MSG, signal_name(WTERMSIG(status))), 0);
  else if (WIFSTOPPED(status))
      if (WSTOPSIG(status) != SIGTRAP && WSTOPSIG(status) != SIGSTOP)
	return (printf(SIGNAL_RCV_MSG, signal_name(WSTOPSIG(status))), 0);
  return (1);
}
