#ifndef _log_h_
#define _log_h_
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef enum 
{
	ERROR = 0,
	WARNING,
	INFO,
	DEBUG
}server_log_id_t;

typedef int log_t;

typedef struct
{
	int id;
	char *name;
}server_log_t;

#endif
