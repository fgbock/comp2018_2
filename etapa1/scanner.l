%{
#include "tokens.h

int lineCount;
%}

%%
"\n" {line_number++;}
[,;:()\[\]{}+-|?*/<>=!&%#^.$] {return (int) yytext[0];}

%%

int get_line_number(void){
	return lineCount;
}
