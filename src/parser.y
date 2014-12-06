%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "type.h"
    extern int yylineno;
    int bt;
    int nliste;
    int yylex ();
    int yyerror ();

%}

%token <str> IDENTIFIER 
%token <n> ICONSTANT 
%token <f> FCONSTANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR DO
%type <t> declarator
%type <t> parameter_declaration
%type <lt> parameter_list
%union {
  type_t t;
  type_t lt[1000];
  char *str;
  int n;
  float f;
}
%start program
%%

primary_expression
: IDENTIFIER
| ICONSTANT {printf("%d\n",$1); }
| FCONSTANT {printf("%f\n",$1); }
| '(' expression ')'
| IDENTIFIER '(' ')' 
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
: VOID  {bt = VOID_T;}
| INT  {bt = INT_T;}
| FLOAT {bt = FLOAT_T;}
; 

declarator
: IDENTIFIER  { $$.element_type = bt; $$.kind = -1 ;}
| '*' IDENTIFIER { if(bt == VOID_T) {perror("void* not allowed"); exit(0);} else $$.element_type = bt+1 ; $$.kind = -1;}
| IDENTIFIER '[' ICONSTANT ']' {$$.element_type = bt; $$.kind = 0;
 $$.element_size = $3;}
| declarator '(' parameter_list ')' {$$.element_type = bt; $$.kind = 1; 
$$.element_size = nliste; $$.function_parameters = $3;} 
| declarator '(' ')' {$$.element_type = bt; $$.kind = 1; $$.element_size = 0;}
;

parameter_list
: parameter_declaration {$$[0] = $1; nliste=1;}
| parameter_list ',' parameter_declaration {$$[nliste++] = $3;}
;

parameter_declaration
: type_name declarator {$$ = $2;}
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
| DO  statement  WHILE '(' expression ')' ';'
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
