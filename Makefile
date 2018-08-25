etapa1:
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c main.c
	gcc -o etapa1 main.o lex.yy.o

clean:
	rm -rf etapa1 lex.yy.c lex.yy.o main.o
	
