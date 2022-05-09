#Adeola Oladega and Joy Odeyemi ALX Group Project on Simple Shell Scripting in C Programming.

![alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)
### The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier

### Description

This Shell project is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C as a milestone project for ALX AFRICA SE.

### Installation

All files were compiled on Ubuntu 20.04 LTS using GCC with the following flags: -Wall -Werror -Wextra -pedantic -std=gnu89

### Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl+D.

#### Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

```sh
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).

#### Included Built-Ins

Our shell has the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |


### Included Files

- main.c - functions for calling the shell and initializing the shell struct

### Credits

All code written by Adeola Oladega and Joy Odeyemi.