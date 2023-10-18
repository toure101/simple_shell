#include "shell.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND 20

void prompt(char **av, char **env) {
    char *string = NULL;
    int i, j, status;
    size_t n = 0;
    ssize_t num_char;
    char *argv[MAX_COMMAND];
    pid_t child_pid;

    while (1) {
        if (isatty(STDIN_FILENO))
            printf("tiswork$ ");  // Added a space and $ to indicate the prompt
        num_char = getline(&string, &n, stdin);
        if (num_char == -1) {
            free(string);
            exit(EXIT_FAILURE);
        }
        i = 0;
        while (string[i]) {
            if (string[i] == '\n')
                string[i] = 0;
            i++;
        }

        j = 0;
        argv[j] = strtok(string, " ");
        while (argv[j]) {
            j++;
            if (j >= MAX_COMMAND) {
                fprintf(stderr, "Too many arguments\n");
                exit(EXIT_FAILURE);
            }
            argv[j] = strtok(NULL, " ");
        }

        child_pid = fork();
        if (child_pid == -1) {
            free(string);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0) {
            if (execve(argv[0], argv, env) == -1) {
                printf("%s: No such file\n", av[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
        }
    }
}

