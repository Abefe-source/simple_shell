#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>

/*env.c*/
char *_getenv(const char *name, char **env);

/*free_shell*/
void free_shell(char **argv, char *line);

/*stat_exec.c*/
int stat_exec(char **argv, char *line, size_t i, char **env);
int _strlen(char *);
int print_number(size_t a);

/*path.c*/
char **_path(int argc, char **argv, char **env);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/*built_in.c*/
int builtin(char **env, char **argv, char *line, int extstat);
int _strcmp(const char *s1, char *s2);

/*main.c*/
void getline_fail(char **argv, char *line);
char **tok(char *st, char *dil);
void sighelp(int a);
void prompt(int a);

#endif
