%{
    #include <stdio.h>
    extern int yylineno;
    int bt;
    int nb_args;
    int yylex ();
    int yyerror ();

%}
%type <t> declarator
%type <t> parameter_declaration
%type <lt> parameter_list
%token <str> IDENTIFIER 
%token <n> ICONSTANT 
%token <f> FCONSTANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR DO
%union {
  char *str;
  int n; float f; type_t t; type_t lt[100];
}
%start program
%%

primary_expression
: IDENTIFIER 
| ICONSTANT {printf("%d\n",$1); }
| FCONSTANT {printf("%f\n",$1); }
| '(' expression ')'
| IDENTIFIER '(' ')'{printf("%s\n",$1); }
| IDENTIFIER '(' argument_expression_list ')'
| IDENTIFIER INC_OP
| IDENTIFIER DEC_OP
| IDENTIFIER '[' expression ']'
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: primary_expression
| '-' unary_expression
| '!' unary_expression
;

multiplicative_expression
: unary_expression
| multiplicative_expression '*' unary_expression
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression
| additive_expression '-' multiplicative_expression
;

comparison_expression
: additive_expression
| additive_expression '<' additive_expression
| additive_expression '>' additive_expression
| additive_expression LE_OP additive_expression
| additive_expression GE_OP additive_expression
| additive_expression EQ_OP additive_expression
| additive_expression NE_OP additive_expression
;

expression
: IDENTIFIER '=' comparison_expression
| IDENTIFIER '[' expression ']' '=' comparison_expression
| comparison_expression
;

declaration
: type_name declarator_list ';'
;

declarator_list
: declarator
| declarator_list ',' declarator
;

type_name
: VOID  {bt = VOID;}
| INT   {bt = INT;}
| FLOAT {bt = FLOAT;}
;

declarator
: IDENTIFIER  							{$$.type = bt;$$.size=0;$$.params=NULL;}
| '*' IDENTIFIER 						{if (bt == VOID)
											return EXIT_FAILURE;
										else		
											$$.type = bt+1;$$.size=0;$$.params=NULL;}
| IDENTIFIER '[' ICONSTANT ']' 			{if (bt == INT)
											$$.type=INTVECT;$$.size=$3;$$.params=NULL;
										else
											return EXIT_FAILURE;}
| declarator '(' parameter_list ')'		{$$.type=FUNCTION;$$.size=nb_args;$$.params=append($1.type,parameter_list); //  /!\ la fonction append ne marche pas, il faut faire notre propre fonction /!\ } 
| declarator '(' ')'					{$$.type=FUNCTION;$$.size=0;$$.params=append($1,NULL);}
;

parameter_list
: parameter_declaration						{$$[0]=$1;nb_args=1;}
| parameter_list ',' parameter_declaration	{$$[nb_args++]=$3;}
;

parameter_declaration
: type_name declarator	{$$=$2;} 
;

statement
: compound_statement
| expression_statement 
| selection_statement
| iteration_statement
| jump_statement
;

compound_statement
: '{' '}'
| '{' statement_list '}'
| '{' declaration_list statement_list '}'
;

declaration_list
: declaration
| declaration_list declaration
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';'
;

selection_statement
: IF '(' expression ')' statement
| IF '(' expression ')' statement ELSE statement
;

iteration_statement
: WHILE '(' expression ')' statement
| FOR '(' expression_statement expression_statement expression ')' statement
| DO statement WHILE '('expression')'';'
;

jump_statement
: RETURN ';'
| RETURN expression ';'
;

program
: external_declaration
| program external_declaration
;

external_declaration
: function_definition
| declaration
;

function_definition
: type_name declarator compound_statement
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	    yyparse();
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
	free(file_name);
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    return 0;
}
