/*
** strace.c for epitech in /home/chapui_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr 28 04:18:52 2015 chapui_s
** Last update Sun May 10 22:59:35 2015 chapui_s
*/

#include "strace.h"
#include "types.h"
#include "syscalls.h"
#include "types32.h"
#include "syscalls32.h"

int	trace_pid(int argc __attribute__ ((unused)),
		  char **argv __attribute__ ((unused)))
{
  return (0);
}

int		get_archi(char *filename)
{
  int		fd;
  Elf32_Ehdr	header;

  g_archi32 = 0;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, &header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
  {
    close(fd);
    return (-1);
  }
  if (header.e_machine == EM_386)
    g_archi32 = 1;
  else if (header.e_machine != EM_X86_64)
  {
    close(fd);
    return (derrorn("Unsupported format"));
  }
  close(fd);
  return (0);
}

int	run_prog(int argc __attribute__ ((unused)),
		 char **argv,
		 char **env,
		 char *path)
{
  if (g_archi32)
    printf("[ Process PID=%d runs in 32 bit mode. ]\n", getpid());
  if (ptrace(PTRACE_TRACEME, 0, 0, 0, 0) == -1)
  {
    return (derror("ptrace"));
  }
  if (execve(path, &argv[1], env) == -1)
  {
    return (derror("execve"));
  }
  return (0);
}

int		is_syscall_defined(unsigned num)
{
  size_t	i;

  i = 0;
  while (i < g_size_tab)
  {
    if (g_archi32 && g_syscalls32[i].num == num)
      return (i);
    else if (!g_archi32 && g_syscalls[i].num == num)
      return (i);
    i += 1;
  }
  return (-1);
}

t_print_func	g_print_func[] =
{
  { "mmap", print_mmap },
  { "mmap2", print_mmap2 },
  { "access", print_access },
  { "open", print_open },
  { "read", print_read },
  { "mprotect", print_mprotect },
  { (char *)0, (void *)0 }
};

int		is_functions_associated(char *name)
{
  size_t	i;

  i = 0;
  while (g_print_func[i].name && strcmp(name, g_print_func[i].name))
  {
    i += 1;
  }
  if (g_print_func[i].name)
  {
    return (i);
  }
  else
  {
    return (-1);
  }
}

void		disp_syscall(pid_t pid,
			     struct user_regs_struct *regs,
			     unsigned num,
			     size_t return_value)
{
  int		sys;
  int		fct;
  t_syscalls	*ptr;

  ptr = (g_archi32) ? (g_syscalls32) : (g_syscalls);
  if ((sys = is_syscall_defined(num)) >= 0)
  {
    if ((fct = is_functions_associated(ptr[sys].name)) != -1)
    {
      g_print_func[fct].fct(pid, regs, return_value);
    }
    else
    {
      print_generic(pid, regs, return_value, num);
    }
  }
}

int				run_trace_fork(pid_t child)
{
  struct user_regs_struct	regs;
  struct user_regs_struct	regs_return;
  unsigned short		instr;
  int				wait_status;
  int				sysc;

  wait(&wait_status);
  while (wait_status == 1407)
  {
    sysc = 0;
    ptrace(PTRACE_GETREGS, child, 0, &regs);
    instr = ptrace(PTRACE_PEEKTEXT, child, regs.rip, 0);
    if (g_archi32 == 1 && instr == 0x80CD)
      sysc = 1;
    else if (!g_archi32 && instr == 0x050F)
      sysc = 1;
    if (ptrace(PTRACE_SINGLESTEP, child, 0, 0) == -1)
      return (derror("ptrace"));
    wait(&wait_status);
    ptrace(PTRACE_GETREGS, child, 0, &regs_return);
    if (sysc)
      disp_syscall(child, &regs, regs.rax, regs_return.rax);
  }
  return (wait_status);
}

int	trace_fork(int argc, char **argv, char **env)
{
  pid_t	child;
  char	*path;
  int	status;

  if ((path = get_path(argv[1])))
  {
    if (get_archi(path) == -1)
      return (-1);
    if ((child = fork()) == -1)
      return (derror("fork"));
    else if (!child)
      run_prog(argc, argv, env, path);
    else
    {
      if ((status = run_trace_fork(child)) != 2943)
      	printf("+++ exited with %d +++\n", status);
      else
      	printf("+++ Killed by SIGSEGV (core dumped) +++\n");
    }
    free(path);
  }
  else
    return (derrorn("No such file"));
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  setbuf(stdout, (char *)0);
  if (!(argc - 1))
    return (usage(argv[0]));
  else if (!strcmp(argv[1], "-p"))
    return (trace_pid(argc, argv));
  else
    return (trace_fork(argc, argv, env));
}
