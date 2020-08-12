CC=gcc

program: program.o http.o transmitter.o
	${CC} -o program program.o transmitter.o http.o

program.o: program.c
	${CC} -c program.c

http.o: http.c
	${CC} -c http.c

transmitter.o: transmitter.c
	${CC} -c transmitter.c

clean:
	rm http.o transmitter.o
