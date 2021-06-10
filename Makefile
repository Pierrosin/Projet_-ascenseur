all : main

FLAGS=-Wall -Werror -g

main.o : main.c
	gcc ${FLAGS} -c main.c

date.o : date.c date.h
	gcc ${FLAGS} -c date.c

liste.o : liste.c liste.h date.h
	gcc ${FLAGS} -c liste.c

main : main.o date.o liste.o
	gcc ${FLAGS} -o main main.o date.o liste.o

clean :
	rm -f -rf *.o ./main