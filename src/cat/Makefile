CC = gcc
CFlags = -Wall -Werror -Wextra

Cat = s21_cat
Grep = s21_grep

CompileMain = main.o
Main = main.c
CompileInput = input.o
Input = input.c

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