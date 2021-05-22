/* Assessment */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <utmp.h>

int main(void)
{
	char *user;
	user = getenv("LOGNAME");
	time_t t;
	time(&t);
	struct utmp *n;
	setutent();
	n=getutent();

	printf("\nHello. You are logged in as %s",user);
	printf("\nThe date is %s", ctime(&t));
	printf("\nThe following users are currently logged in:");
	while(n) {
		if(n->ut_type==USER_PROCESS) {
			printf("%9s%12s (%s)\n", n->ut_user, n->ut_line, n->ut_host);
		}
		n=getutent();
	}
	return 0;
}
