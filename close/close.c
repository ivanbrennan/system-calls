#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd1, fd2;

	fd1 = open("/tmp", O_RDONLY);
	if (fd1 < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	fd2 = open("/tmp", O_RDONLY);
	if (fd2 < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("Opened /tmp twice: fd's are %d and %d.\n", fd1, fd2);

	if (close(fd1) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (close(fd2) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("Closed both fd's.\n");

	fd2 = open("/tmp", O_RDONLY);
	if (fd2 < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("Reopened /tmp into fd2: %d.\n", fd2);

	if (close(fd2) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("Closed fd2. Now calling close(fd2) again.\n");
	printf("This should cause an error.\n\n");

	if (close(fd2) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	printf("This should never be reached.\n");

	return 0;
}
