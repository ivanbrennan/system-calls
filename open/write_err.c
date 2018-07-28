#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("/tmp/does_not_exist", O_WRONLY);
	if (fd < 0) {
		perror("/tmp/does_not_exist");
		exit(EXIT_FAILURE);
	}

	return 0;
}
