CC = gcc
CFlags = -Wall -Werror -Wextra

Cat = s21_cat

CompileMain = main.o
Main = main.c
CompileInput = s21_cat.o
Input = s21_cat.c

all: $(Cat)

$(CompileMain):
	$(CC) $(CFlags) -c -o $(CompileMain) $(Main)

$(CompileInput):
	$(CC) $(CFlags) -c -o $(CompileInput) $(Input)

$(Cat): $(CompileMain) $(CompileInput)
	$(CC) $(CFlags) -o $(Cat) $(CompileInput) $(CompileMain) 

clean:
	rm -rf $(Cat) *.o

rebuild: clean all