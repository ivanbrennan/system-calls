#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (system("ls -lAh") == -1) {
		perror("system");
		exit(EXIT_FAILURE);
	} else {
		printf("Done\n");
	}

	return 0;
}
