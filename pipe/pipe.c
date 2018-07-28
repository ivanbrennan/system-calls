#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t cpid;
	char buf;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	cpid = fork();
	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {      /* Child reads from pipe */
		close(pipefd[1]); /* Close write end */
		while (read(pipefd[0], &buf, 1) > 0) {
			if (write(STDOUT_FILENO, &buf, 1) == -1) {
				perror("write");
				exit(EXIT_FAILURE);
			}
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
		close(pipefd[0]);
	} else {              /* Parent writes to pipe */
		close(pipefd[0]); /* Close read end */
		if (write(pipefd[1], argv[1], strlen(argv[1])) == -1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]); /* Reader will see EOF */
		wait(NULL);       /* Wait for child */
	}

	exit(EXIT_SUCCESS);
}
