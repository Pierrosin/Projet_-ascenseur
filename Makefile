
all : main

FLAGS=-Wall -Werror -g

main.o : main.c
	gcc ${FLAGS} -c main.c

elevator.o : elevator.c elevator.h
	gcc ${FLAGS} -c elevator.c

person.o : person.c person.h elevator.h
	gcc ${FLAGS} -c person.c

main : main.o elevator.o person.o
	gcc ${FLAGS} -o main main.o elevator.o person.o -lncurses

clean :
	rm -f -rf *.o ./main
