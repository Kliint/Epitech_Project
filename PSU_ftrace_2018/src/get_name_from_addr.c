#define _GNU_SOURCE
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <dlfcn.h>
#include "ftrace.h"

char	*get_name_from_addr(long_stuff addr)
{
  char	*res;

  if ((res = static_name_resolv(addr)) != NULL)
    return (strdup(res));
  if ((res = dynamic_name_resolv(addr)) != NULL)
    return (res);
  asprintf(&res, "func_0x%llX@%s", addr, rindex(g_bin.name, '/') + 1);
  return (res);
}
