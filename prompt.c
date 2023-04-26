#include "main.h"

/**
 * prompt - Function that displays a command promtp to the user
 * @av: COmmand line arguments
 * @envp: Environmental variable
 * Return: void
 */

void prompt(char **av, char **envp)
{
	char *lineptr = NULL, *argv[MAX_ENTRY];
	size_t n = 0;
	int i, wstatus, j;
	ssize_t stream;
	pid_t pid;

	while (1)
	{
		printf("EnterCmd$ ");

		stream = getline(&lineptr, &n, stdin);
		if (stream == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
			{
				lineptr[i] = 0;
			}
			i++;
		}
        j = 0
		argv[j] = strtok(lineptr, " ");
        while (arg[j] != NULL)
        {
            j++;
            argv[j] = strtok(NULL, " ");
        }
		pid = fork();
		if (pid == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		{
			wait(&wstatus);
		}
	}
}
