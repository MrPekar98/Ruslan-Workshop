C=gcc

program: http.o transmitter.o
        $(C) -o program http.o transmitter.o

http.o: http.c
        $(C) -c http.c

transmitter.o: transmitter.c
        $(C) -c transmitter.c

clean:
        rm http.o transmitter.o
