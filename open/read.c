#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("/tmp", O_RDONLY);
	printf("%d\n", fd);

	return 0;
}
