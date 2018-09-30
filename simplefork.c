/* simplefork.c */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main () 
{
	pid_t child_id;
	child_id = fork();
	if ( child_id == 0 )
	{
		printf("Child: My PID = %d and my parent PID = %d\n", getpid(), getppid());
		_exit(EXIT_SUCCESS);
	}
	if ( child_id < 0 )
	{
		fprintf(stderr, "Fork failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Parent: My PID = %d, spawned child PID = %d\n", getpid(), child_id);
	return EXIT_SUCCESS;
}
