#include <sys/time.h>
#include <stdio.h>

// 1 second -> 1 000 000 microseconds
// 1 second -> 1 000 milliseconds

// divide by 60 seconds / 60 minutes / 24 hours / 365 days

int main (int argc, char **argv)
{
	struct timeval time;
	gettimeofday(&time, NULL);

	printf("time tv_sec: %ld\n", time.tv_sec);
	printf("time tv_usec: %ld\n", time.tv_usec);
	printf("time divided: %ld\n", time.tv_sec / 60 / 60 / 24 / 365);
	return 0;
}


// for philo we need to save the starting time 
