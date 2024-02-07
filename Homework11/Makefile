all: prog

prog: main.o temp_functions.o temp_functions.h
	gcc -o prog main.o temp_functions.o

main.o: main.c 
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	del *.o
	del prog.exe