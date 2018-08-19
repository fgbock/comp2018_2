comp:
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c main.c
	gcc -o comp main.o lex.yy.o

clean:
	rm -rf comp lex.yy.c lex.yy.o main.o
	
