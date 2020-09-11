#donner nom pour ne modifier que cette partie quand on refait un Makefile
CC=gcc
CFlags= -Wall  #permet d'afficher des messages d'erreur
LDFLAGS=-lncurses  #fais des curseurs

PROG=main
OBJ= main.o elevator.o person.o #intermédiare pour éviter de tout recompiler à chaque changement


#code 
all: $(PROG)
		./$(PROG)

clean: 
		rm -f *.o 
		#nettoie .o
		rm -f $(PROG)

$(PROG): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 
#compile 

#détail de OBJ

main.o: main.c elevator.h
	$(CC) $(CFlags) -o $@ -c $<

person.o : person.c person.h
	$(CC) $(CFlags) -o $@ -c $<

elevator.o: elevator.c elevator.h person.h
	$(CC) $(CFlags) -o $@ -c $<

