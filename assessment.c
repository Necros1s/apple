#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/utsname.h>
#include <errno.h>

int main(void) {
	char *user;
	char *hstnm[1024];
	user = getenv("LOGNAME");
	gethostname(hstnm, 1024);
	time_t t;
	time(&t);

	struct utsname buffer;

	errno = 0;
	if (uname(&buffer) < 0) {
		perror("uname");
		exit(EXIT_FAILURE);
	}

	system("clear");

	printf("\nHello. You are logged in as %s.",user);
	printf("\nThe date is %s", ctime(&t));
	printf("\nThe following users are currently logged in:");
	printf("\n");
	system("w");
	printf("\nThe hostname is %s",hstnm);
	printf("\n");
	printf("\nThe kernel version is: %s", buffer.release);
	printf("\n");
	printf("\nThe current disk usage: \n");
	system("df -BG /");
	printf("\n");
	return 0;
}
