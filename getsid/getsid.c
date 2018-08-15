#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = getpid();
	pid_t sid = getsid(0);

	printf("PID: %d, SID: %d\n", pid, sid);

	return 0;
}
