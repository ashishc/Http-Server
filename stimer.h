#ifndef _stimer_h
#define _stimer_h
#include <time.h>
#include <sys/time.h>

typedef struct
{
	struct timespec tstart;
	struct timespec tend;
	struct timespec difference;
	struct timespec total_difference;
}stimer_t;

#endif
