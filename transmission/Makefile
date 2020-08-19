CC=gcc
PLATFORMFLAG=-DLINUX
CFLAGS=-Wall -pedantic -pthread
WINFLAGS=-lws2_32

program: program.o http.o transmitter.o
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -o program program.o transmitter.o http.o $(WINFLAGS)
else
	$(CC) $(CFLAGS) -o program program.o transmitter.o http.o
endif

program.o: program.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c program.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c program.c $(PLATFORMFLAG)
endif

http.o: http.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c http.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c http.c $(PLATFORMFLAG)
endif

transmitter.o: transmitter.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) $(CFLAGS) -c transmitter.c $(PLATFORMFLAG) $(WINFLAGS)
else
	$(CC) $(CFLAGS) -c transmitter.c $(PLATFORMFLAG)
endif

clean:
	rm http.o transmitter.o program.o
