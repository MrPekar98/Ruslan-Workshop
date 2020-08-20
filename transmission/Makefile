CC=gcc
INC=../lib/json-parser
PLATFORMFLAG=-DLINUX
CFLAGS=../lib/json-parser/json.c -lm -pthread -pedantic -I $(INC)
WINFLAGS=-lws2_32

program: program.c http.c transmitter.c
ifeq ($(PLATFORMFLAG), -DWINDOWS)
	$(CC) -o program program.c http.c transmitter.c $(CFLAGS) $(WINFLAGS) $(PLATFORMFLAG)
else
	$(CC) -o program program.c http.c transmitter.c $(CFLAGS) $(PLATFORMFLAG)
endif

clean:
	rm program
