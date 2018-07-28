#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;

	fd = open("/tmp/did_not_exist", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("/tmp/did_not_exist");
		exit(EXIT_FAILURE);
	}

	return 0;
}
