#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>

/*env.c*/
char *_getenv(const char *name, char **env)
char **_path(int argc, char **argv, char **env)
