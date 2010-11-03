#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "polalib.h"

int open(const char *cmd_path, int flags, ...)
{
    int (*lib_open) (const char*, int, ...);
    char path[256];

    printf("entering open(): %s\n", path);

    strcpy(path, cmd_path);
	
    if(parser(path, flags) != 0)
    {
        printf("Erreur sur de parsing");
        exit(1);
    }

    lib_open = dlsym(RTLD_NEXT, "open");

    if (dlerror())
	{
        return -1;
	}
	
    // les ... 
    if (flags & O_CREAT)
    {
        va_list arg_list;
        mode_t mode;
        va_start(arg_list, flags);
        mode = va_arg(arg_list, mode_t);
        va_end(arg_list);
        return real_open(path, flags, mode);
    }
    else
    {
        return lib_open(path, flags);
    }
}

int open64(const char *path, int flags, ...)
{
	int (*lib_open) (const char*, int, ...);
    char path[256];

    printf("entering open(): %s\n", path);

    strcpy(path, cmd_path);
	

    if(parser(path, flags) != 0)
    {
        printf("Erreur sur de parsing");
        exit(1);
    }

    lib_open = dlsym(RTLD_NEXT, "open64");

    if (dlerror())
	{
        return -1;
	}
	
    if (flags & O_CREAT)
    {
        va_list arg_list;
		mode_t mode;
        va_start(arg_list, flags);
        mode = va_arg(arg_list, mode_t);
        va_end(arg_list);
        return real_open(path, flags, mode);
    }
    else
    {
        return lib_open(path, flags);
    }
}

int openat(int dirfd, const char *path, int flags, ...)
{
    int (*lib_openat) (const char*, int, ...);
    char path[256];

    printf("entering open(): %s\n", path);

    strcpy(path, cmd_path);
	

    if(parser(path, flags) != 0)
    {
        printf("Erreur sur de parsing");
        exit(1);
    }

    lib_openat = dlsym(RTLD_NEXT, "open");

    if (dlerror())
	{
        return -1;
	}
	
    // les ... 
    if (flags & O_CREAT)
    {
        va_list arg_list;
        mode_t mode;
        va_start(arg_list, flags);
        mode = va_arg(arg_list, mode_t);
        va_end(arg_list);
        return real_open(real_path, flags, mode);
    }
    else
    {
        return real_open(real_path, flags);
    }
}


DIR *opendir(const char *name)
{
    DIR *dir_return;
    DIR *(*lib_opendir)(const char *);

    
    real_opendir = dlsym(RTLD_NEXT, "opendir");

    dir_return = lib_opendir(name);

    return dir_return;
}