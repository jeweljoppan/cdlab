
%{
#include<stdio.h>
%}

%token SW OB CB ID NL COB CCB CS Q BR SEM NUM

%%

S : X NL {printf("Valid");}
  ;
X : SW OB ID CB NL COB NL Y Y Y Y Y NL CCB
  ;
Y : CS NUM Q ID NL BR SEM NL |
  ;

%%
int yyerror()
{
	printf("Invalid\n");
}
void main()
{
	yyparse();
}

