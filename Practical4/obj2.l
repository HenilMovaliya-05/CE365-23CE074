%{
#include <stdio.h>
%}

%%
charusat|Charusat|CHARUSAT    { printf("university"); }
\n          { printf("\n"); }
.           { printf("%s", yytext); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
