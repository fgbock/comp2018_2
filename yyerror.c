#include <stdio.h>
void yyerror(char const *s)
{
  printf("error: %s\n",s);
}
