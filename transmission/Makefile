CC=gcc
CFLAGS=-DLINUX

program: program.o http.o transmitter.o
	${CC} -o program program.o transmitter.o http.o

program.o: program.c
	${CC} -c program.c $(CFLAGS)

http.o: http.c
	${CC} -c http.c $(CFLAGS)

transmitter.o: transmitter.c
	${CC} -c transmitter.c $(CFLAGS)

clean:
	rm http.o transmitter.o program.o
