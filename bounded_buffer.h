#ifndef _bounded_buffer_h_
#define _bounded_buffer_h_
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
typedef struct
{
	int * buffer;
	int   buf_in;
	int   buf_out;
	int   buffer_max;
}bounded_buffer_t;


#endif
