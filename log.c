#include "log.h"
log_t current_log_no = WARNING;

int get_log_id()
{
	return current_log_no;
}

void set_log(const char * log_name)
{
	if(strstr(log_name,"ERROR")        || strstr(log_name,"error"))   current_log_no = ERROR;
	else if(strstr(log_name,"WARNING") || strstr(log_name,"warning")) current_log_no = WARNING;
	else if(strstr(log_name,"INFO")    || strstr(log_name,"info"))    current_log_no = INFO;
	else if(strstr(log_name,"DEBUG")   || strstr(log_name,"debug"))   current_log_no = DEBUG;
	else   current_log_no = atoi(log_name); 
}

int print_log(log_t log_level,char * fmt, ...)
{
	if(log_level > get_log_id())
		return 0;
	int print_count;
	va_list myargs;
	va_start(myargs,fmt);
	print_count = vfprintf(stderr,fmt,myargs);
	va_end(myargs);
	return print_count;
}

void set_next_log()
{
	if(current_log_no == DEBUG) 
	{
		current_log_no = ERROR;
		return;
	}
	current_log_no++;
}
