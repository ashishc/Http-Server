#include "stimer.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#define TIME_MAX 100
#define TIME_WRAP 60;
#include <semaphore.h>
#include <pthread.h>
pthread_mutex_t lock_time_mtx = PTHREAD_MUTEX_INITIALIZER;

char time_diff[TIME_MAX];

void s_start(stimer_t *s_clock)
{
//	pthread_mutex_lock(&lock_time_mtx);
	clock_gettime(CLOCK_MONOTONIC, &(s_clock->tstart));
//	pthread_mutex_unlock(&lock_time_mtx);
}

void s_stop(stimer_t *s_clock)
{
//	pthread_mutex_lock(&lock_time_mtx);
	clock_gettime(CLOCK_MONOTONIC, &(s_clock->tend));
//	pthread_mutex_unlock(&lock_time_mtx);
}

void get_time_difference(stimer_t *s_clock)
{
//	pthread_mutex_lock(&lock_time_mtx);
	s_clock->difference.tv_sec  = abs(s_clock->tend.tv_sec  - s_clock->tstart.tv_sec);
	s_clock->difference.tv_nsec = abs(s_clock->tend.tv_nsec - s_clock->tstart.tv_nsec);
	s_clock->total_difference.tv_sec  += s_clock->difference.tv_sec;
	s_clock->total_difference.tv_nsec += s_clock->difference.tv_nsec;
//	pthread_mutex_unlock(&lock_time_mtx);
}

char* show_time_difference(stimer_t *s_clock)
{
	long int minutes=0,hours=0;
	minutes = s_clock->difference.tv_sec / 60;
	hours   = minutes / 60;
	sprintf(time_diff,"%ld hr,%ld min, %ld.%ld seconds",hours,minutes,s_clock->difference.tv_sec%60,s_clock->difference.tv_nsec);
	return time_diff;
}

char* show_total_time_difference(stimer_t * s_clock)
{
	long int minutes=0,hours=0;
	minutes = s_clock->total_difference.tv_sec / 60;
	hours   = minutes/60;
	sprintf(time_diff,"%ld hr,%ld min, %ld.%ld seconds",hours,minutes,s_clock->total_difference.tv_sec%60,s_clock->total_difference.tv_nsec);
	return time_diff;
}

char* show_average_time(stimer_t * s_clock,int quantity)
{
	if(quantity == 0)
	{	
		return "0.0 second";
	}
	sprintf(time_diff,"%ld.%08ld seconds",(s_clock->total_difference.tv_sec / quantity),(s_clock->total_difference.tv_nsec / quantity));
	
	return time_diff;
}
