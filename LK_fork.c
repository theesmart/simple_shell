#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * run_command - runs a command and awaits its completion
 * @command_path: the command path to execute
 * @tokens: the command-line arguments array
 * @e_status: the store exit status of the command
 *
 * Return: 0 on success, -1 on failure
 */
int run_command(char *command_path, char **tokens, int *e_status)
{
	pid_t child_pid;
	int child_exit_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error forking process");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(command_path, tokens, environ);
		perror("Execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&child_exit_status);
		if (WIFEXITED(status))
		    *e_status = WEXITSTATUS(child_exit_status);
		else
		    *e_status = -1;
	}
	return (0);
}
