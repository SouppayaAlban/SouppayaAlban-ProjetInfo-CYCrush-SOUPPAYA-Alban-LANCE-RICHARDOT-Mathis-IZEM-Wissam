all: exec

main.o : main.c fonctions.h
	gcc -c main.c -o main.o

fonctions.o : fonctions.c fonctions.h
	gcc -c fonctions.c -o fonctions.o

CYcrush.o : CYcrush.c fonctions.h
	gcc -c CYcrush.c -o CYcrush.o
	
exec : main.o fonctions.o CYcrush.o
	gcc main.o fonctions.o CYcrush.o -o exec
