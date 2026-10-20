game: main.o
	gcc main.o -o game 

main.o : main.c
		gcc -c main.c -o main.o

run: game
	./game
clean: 
	rm -f *.out *.o game

.PHONY: run clean