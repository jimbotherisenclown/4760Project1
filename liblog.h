#include <time.h>

typedef struct data_struct {
		time_t  time;
		char    type;
		char*   string;
} data_t;

//Save a message at the end of a list & log time of the message. Return 0 on success / -1 on failure.
//Set errno (part of perror on failure).
int addmsg ( const char type, const char * msg );

//Release storage allocated for logged message & empty list of logged messages.
void clearlog();

//Allocate space for a string containing the entire log, copy the log into the string, and return a 
//pointer to the string. Return NULL on unsuccessful invocation. Set errno (part of perror) on failure.
char * getlog();

//Save to a diskfile. Return 0 on success / -1 on failure. Set errno (part of perror) on failure.
int savelog (char * filename );
