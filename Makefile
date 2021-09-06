C      = gcc
CFLAGS = -g
TARGET = logger
OBJS   = logger.o

$(TARGET) : $(OBJS)
   $(CC) -o $(TARGET) $(OBJS)

logger.o: logger.c
   $(CC) -o $(CFLAGS) -c logger.c

.PHONY: clean

clean:
   /bin/rm -f *.o $(TARGET)
