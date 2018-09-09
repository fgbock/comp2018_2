#include <stdio.h>
extern int lineCount;
void yyerror(char const *s)
{
  printf("error on line %d: %s\n", lineCount, s);
}
