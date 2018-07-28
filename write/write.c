#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int fd;
	ssize_t sz;

	fd = open("/tmp/will_get_truncated", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("write");
		exit(EXIT_FAILURE);
	}

	sz = write(fd, "we wrote this\n", strlen("we wrote this\n"));

	printf("Called write(%d, \"we wrote this\\n\", %ld) and it returned %ld\n",
			fd, strlen("we wrote this\n"), sz);

	close(fd);

	return 0;
}
