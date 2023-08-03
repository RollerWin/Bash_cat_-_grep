CC = gcc
CFlags = -Wall -Werror -Wextra

Grep = s21_grep

CompileMain = main.o
Main = main.c
CompileInput = s21_grep.o
Input = s21_grep.c

all: $(Grep)

$(CompileMain):
	$(CC) $(CFlags) -c -o $(CompileMain) $(Main)

$(CompileInput):
	$(CC) $(CFlags) -c -o $(CompileInput) $(Input)

$(Grep): $(CompileMain) $(CompileInput)
	$(CC) $(CFlags) -o $(Grep) $(CompileInput) $(CompileMain) 

clean:
	rm -rf $(Grep) *.o

rebuild: clean all