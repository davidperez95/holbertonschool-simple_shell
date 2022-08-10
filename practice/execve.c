#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int i = 0;
	int status;
	pid_t child_pid;
	pid_t father_pid;
	
	while (i < 5)
	{	
		child_pid = fork();
		father_pid = getpid();
		if (child_pid == -1)
		{
			perror("error:");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("before execve, father pid is: %u\n", father_pid);
			if (execve(argv[0], argv, NULL) == -1)
				perror("error:");
			printf("after execve, father pid is: %u\n", father_pid);
			sleep(3);
		}
		else
		{
			wait(&status);
			printf("im the father with pid: %u\n", father_pid);
		}
		i++;
	}
	return (0);
}
