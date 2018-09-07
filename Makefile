etapa2: 
	bison -d -v parser.y
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c main.c
	gcc -o etapa2 main.o yyerror.o parser.tab.o lex.yy.o

debug: 
	bison -d -v parser.y --report-file=REPORTFILE
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c main.c
	gcc -o etapa2 main.o yyerror.o parser.tab.o lex.yy.o

clean:
	rm -rf etapa2 lex.yy.c lex.yy.o main.o yyerror.o parser.tab.c parser.tab.h parser.tab.o parser.output
	
