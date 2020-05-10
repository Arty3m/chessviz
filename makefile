all: main

main: bin/main

bin/main: build/main.o build/board.o build/printboard.o
	gcc -Wall -Werror build/main.o build/board.o build/printboard.o -o bin/main

build/main.o: src/main.c
	gcc -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -Wall -Werror src/board.c -o build/board.o

build/printboard.o: src/printboard.c
	gcc -Wall -Werror src/printboard.c -o build/printboard.o

clean:
	rm -rf build/*.o
