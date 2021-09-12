#Benjamin West
#4760 Project1
#Fall Semester 2021

CC     = gcc                           #Compiler set to gcc
CFLAGS = -g -Wall                      #Flags passed to gcc. -g -> Debug messages; -Wall -> warning flags
DFLAGS = -c                            #Flags passed to gcc. Intended to allow additional values beyond CFLAGS
SHELL  = /bin/sh                       #Included per conventions (As mentioned in GNU Make V4.3, ch. 16) 

SRCS   := $(wildcard *.c)              #Stores all files in folder where make was run with the .c extension
BINS   := $(SRCS:%.c=%)                #Stores all values in SRCS as vars without the .c extension

all    : $(BINS)                       #All values stored in BINS are executed as separate targets

%      : %.o                           #Expands each value in BINS and targets %.o with the same value
	${CC} ${CFLAGS} $< -o $@       #Compiles with the appropriate flags, $< -o $@ expand to foo.o -o foo on execution

%.o    : %.c                           #Expands the value passed from % and sets foo.c as a prerequisite name
	${CC} ${DFLAGS} $<                    #Compiles the foo.o file into foo.c.

.PHONY : 
	clean                          #Sets clean as a PHONY target

clean  : 
	/bin/rm -f *.o ${BINS}         #Removes all .o files with names corresponding to the values stored in BINS
