#include <stdlib.h>
#include <sys/ptrace.h>
#include "ftrace.h"

long_stuff	*tab_no_l0rmb17(t_call *call, t_rex *rex,
				long_stuff opcode)
{
  long_stuff	*tab;

  tab = malloc(8 * sizeof(long));
  tab[0] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rax);
  tab[1] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rcx);
  tab[2] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdx);
  tab[3] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbx);
  tab[4] = ptrace(PTRACE_PEEKTEXT, g_pid, get_sib((opcode & 0xFF0000) >> 16,
						  call, rex, 0));
  tab[5] = ptrace(PTRACE_PEEKTEXT, g_pid,
		  call->regs.rip + 6
		  + (ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 2)
		     & 0xFFFFFFFF));
  tab[6] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rsi);
  tab[7] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdi);
  return (tab);
}

long_stuff	*tab_yes_l0rmb17(t_call *call, t_rex *rex,
				 long_stuff opcode)
{
  long_stuff	*tab;

  tab = malloc(8 * sizeof(long));
  tab[0] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r8);
  tab[1] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r9);
  tab[2] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r10);
  tab[3] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r11);
  tab[4] = ptrace(PTRACE_PEEKTEXT, g_pid, get_sib((opcode & 0xFF0000) >> 16,
						  call, rex, 0));
  tab[5] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 6
		  + (ptrace(PTRACE_PEEKTEXT, g_pid,
			    call->regs.rip + 2) & 0xFFFFFFFF));
  tab[6] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r14);
  tab[7] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r15);
  return (tab);
}

long_stuff	l0rmb17(t_call *call, t_rex *rex,
			long_stuff rmb, long_stuff opcode)
{
  long_stuff	*tab;
  long_stuff addr;

  if (!rex->b)
    tab = tab_no_l0rmb17(call, rex, opcode);
  else
    tab = tab_yes_l0rmb17(call, rex, opcode);
  addr = tab[rmb & 0x0F];
  free(tab);
  return (addr);
}
