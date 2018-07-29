#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
	int i, resource = -1;
	struct rlimit rlim;

	int resources[16] = {
		RLIMIT_AS, RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA,
		RLIMIT_FSIZE, RLIMIT_LOCKS, RLIMIT_MEMLOCK, RLIMIT_MSGQUEUE,
		RLIMIT_NICE, RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_RSS,
		RLIMIT_RTPRIO, RLIMIT_RTTIME, RLIMIT_SIGPENDING, RLIMIT_STACK
	};

	char *resource_names[16] = {
		"RLIMIT_AS", "RLIMIT_CORE", "RLIMIT_CPU", "RLIMIT_DATA",
		"RLIMIT_FSIZE", "RLIMIT_LOCKS", "RLIMIT_MEMLOCK", "RLIMIT_MSGQUEUE",
		"RLIMIT_NICE", "RLIMIT_NOFILE", "RLIMIT_NPROC", "RLIMIT_RSS",
		"RLIMIT_RTPRIO", "RLIMIT_RTTIME", "RLIMIT_SIGPENDING", "RLIMIT_STACK"
	};

	if (argc != 2) {
		printf("Usage: %s <resource>\n\n", argv[0]);
		printf("Available resources:");
		for (i = 0; i < 16; i++) {
			printf(" %s", resource_names[i]);
		}
		printf("\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 16; i++) {
		if (strcmp(argv[1], resource_names[i]) == 0) {
			resource = resources[i];
			break;
		}
	}

	if (resource == -1) {
		printf("Invalid resource.\n");
		printf("Choose one of:");
		for (i = 0; i < 16; i++) {
			printf(" %s", resource_names[i]);
		}
		printf("\n");
		exit(EXIT_FAILURE);
	}

	if (getrlimit(resource, &rlim) == -1) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}

	printf("Soft limit: %lld\n", (long long) rlim.rlim_cur);
	printf("Hard limit: %lld\n", (long long) rlim.rlim_max);

	return 0;
}
