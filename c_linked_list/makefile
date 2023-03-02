demo: linked_list.o main.o
	gcc -Wall -Wextra -std=c11 -fmax-errors=10 -g linked_list.o  main.o -o demo

linked_list.o: linked_list.c linked_list.h
	gcc -Wall -Wextra -std=c11 -fmax-errors=10 -g -c linked_list.c -o linked_list.o


main.o: main.c linked_list.h
	gcc -Wall -Wextra -std=c11 -fmax-errors=10 -g -c main.c -o main.o

run: main 
	./demo

clean: 
	rm *.o
