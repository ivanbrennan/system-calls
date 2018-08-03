#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Usage:
 *   $ ./waitpid &
 *   Child PID is 32360
 *   [1] 32359
 *   $ kill -STOP 32360
 *   stopped by signal 19
 *   $ kill -CONT 32360
 *   continued
 *   $ kill -TERM 32360
 *   killed by signal 15
 *   [1]+  Done
 *   $
 */

int main(int argc, char *argv[])
{
	pid_t cpid, w;
	int status;

	cpid = fork();
	if (cpid ==  -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {
		/* child */
		printf("Child PID is %ld\n", (long) getpid());
		if (argc == 1) {
			pause(); /* wait for signals */
		}
		_exit(atoi(argv[1]));
	} else {
		/* parent */
		do {
			w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
			if (w == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status)) {
				printf("exited, status=%d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("killed by signal %d\n", WTERMSIG(status));
			} else if (WIFSTOPPED(status)) {
				printf("stopped by signal %d\n", WSTOPSIG(status));
			} else if (WIFCONTINUED(status)) {
				printf("continued\n");
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		exit(EXIT_SUCCESS);
	}
}
