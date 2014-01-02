#include "bounded_buffer.h"

bounded_buffer_t bb;

void init_buffer(int buffer_max)
{
	bb.buffer = (int*)malloc(sizeof(int)*buffer_max);
	bb.buffer_max =buffer_max;
}

int buffer_add(int item)
{
	if(bb.buf_in == INT_MAX) bb.buf_in = 0;
	if((bb.buf_in - bb.buf_out) >= 0 && abs(bb.buf_in - bb.buf_out) < bb.buffer_max)
	{
		bb.buffer[ bb.buf_in % bb.buffer_max ] = item;
		bb.buf_in ++;
		return 1;
	}
	return 0;
}

int buffer_get()
{
	if(bb.buf_out == INT_MAX) bb.buf_out = 0;
	if((bb.buf_in - bb.buf_out) > 0 && abs(bb.buf_in - bb.buf_out) < bb.buffer_max)
	{
		int peer_sfd = bb.buffer[ bb.buf_out % bb.buffer_max ];
		bb.buf_out++;
		return peer_sfd; 
	}
	return -1;
}

int is_buffer_full()
{
	if(abs(bb.buf_out - bb.buf_in) == bb.buffer_max-1)
		return 1;
	return 0;
}

int is_buffer_empty()
{
	if(bb.buf_in == bb.buf_out)
		return 1;
	return 0;
}

void destroy_buffer()
{
	free(bb.buffer);
}
