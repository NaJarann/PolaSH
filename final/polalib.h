#ifndef _POLALIB_
#define _POLALIB_

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

int parser(char *cmd, int flags);
int unpars_name(char *name, int inf, int sup, int plus);

#endif