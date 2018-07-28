#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("/tmp/does_not_exist", O_RDONLY);
	printf("%d\n", fd);

	return 0;
}
