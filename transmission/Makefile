CC=gcc
PLATFORMFLAG=-DWINDOWS
CFLAGS=-Wall
WINFLAGS=-lws2_32

program: program.o http.o transmitter.o
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -o program program.o transmitter.o http.o $(WINFLAGS)
else
	$(CC) $(CFLAGS) -o program program.o transmitter.o http.o

program.o: program.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c program.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c program.c $(PLATFORMFLAG)

http.o: http.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c http.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c http.c $(PLATFORMFLAG)

transmitter.o: transmitter.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c transmitter.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c transmitter.c $(PLATFORMFLAG)

clean:
	rm http.o transmitter.o program.o
