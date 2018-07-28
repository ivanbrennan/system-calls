#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *buff;
	int fd;
	ssize_t sz;

	buff = (char *) malloc(100 * sizeof(char));
	fd = open("/etc/zoneinfo/zone.tab", O_RDONLY);
	if (fd < 0) {
		perror("read");
	}

	sz = read(fd, buff, 74);
	printf("Called read(%d, buff, 74) and read %ld bytes.\n", fd, sz);
	buff[sz] = '\0';
	printf("Data read:\n%s\n", buff);

	sz = read(fd, buff, 99);
	printf("\nCalled read(%d, buff, 99) and read %ld bytes.\n", fd, sz);
	buff[sz] = '\0';
	printf("Data read:\n%s\n", buff);

	close(fd);
	free(buff);

	return 0;
}
