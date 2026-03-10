CC = gcc
CFLAGS = -Wall -Wextra

all: prog

prog: src/main.o src/process.o
	$(CC) src/main.o src/process.o -o prog

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/process.o: src/process.c
	$(CC) $(CFLAGS) -c src/process.c -o src/process.o

clean:
	rm -f src/*.o prog output.txt