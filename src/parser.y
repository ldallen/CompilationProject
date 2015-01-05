%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "type.h"
    extern int yylineno;
    int bt;
    int nliste = 0;
    int dliste = 0;
    int level = 0;
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
| IDENTIFIER '(' ')' {if(!($1.t.element_type == VOID_T) && $1.t.kind == 1){
     if($1.t.element_type == INT_T || $1.t.element_type == INTSTAR_T || $1.t.element_type == FLOATSTAR_T) {printf("%d\n", $1.n);}
     if($1.t.element_type == FLOAT_T) {printf("%f\n",$1.f);}
}} 
| IDENTIFIER '(' argument_expression_list ')' {if(!($1.t.element_type == VOID_T) && $1.t.kind == 1){
     if($1.t.element_type == INT_T || $1.t.element_type == INTSTAR_T || $1.t.element_type == FLOATSTAR_T) {printf("%d\n", $1.n);}
     if($1.t.element_type == FLOAT_T) {printf("%f\n",$1.f);}
}}
| IDENTIFIER INC_OP {if($1.t.element_type == INT_T && $1.t.kind == -1) {$1.n = ($1.n ++); printf("%d\n",$1.n);}}
| IDENTIFIER DEC_OP {if($1.t.element_type == INT_T && $1.t.kind == -1) {$1.n = ($1.n --); printf("%d\n",$1.n);}} 
| IDENTIFIER '[' expression ']' {if($1.t.kind == 0) {if($1.t.element_type == INT_T) printf("%d\n", $1[$3.n].n); 
     else if($1.t.element_type == FLOAT_T) printf("%f\n", $1[$3.n].f);}}
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: primary_expression {if ($1.t.element_type == INT_T)
     $$.n =  $1.n;
     else if ($1.t.element_type == FLOAT_T)
       $$.f = $1.f;}
| '-' unary_expression {if ($2.t.element_type == INT_T)
     $$.n = - $2.n;
     else if ($2.t.element_type == FLOAT_T)
       $$.f = - $2.f;}
| '!' unary_expression {if ($2.t.element_type == INT_T)
      $$.n = (! $2.n);
     else if ($2.t.element_type == FLOAT_T)
       $$.f = (! $2.f);}
;

multiplicative_expression
: unary_expression {if ($1.t.element_type == INT_T)
     $$.n =  $1.n;
     else if ($1.t.element_type == FLOAT_T)
       $$.f = $1.f;}
| multiplicative_expression '*' unary_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      $$.n = $1.n * $3.n;
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.n * $3.f;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
      $$.f = $1.f * $3.n;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.f * $3.f;
}
;

additive_expression
: multiplicative_expression {if ($1.t.element_type == INT_T)
     $$.n =  $1.n;
     else if ($1.t.element_type == FLOAT_T)
       $$.f = $1.f;}
| additive_expression '+' multiplicative_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      $$.n = $1.n + $3.n;
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.n + $3.f;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
      $$.f = $1.f + $3.n;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.f + $3.f;
}
| additive_expression '-' multiplicative_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      $$.n = $1.n - $3.n;
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.n - $3.f;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
      $$.f = $1.f - $3.n;
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
      $$.f = $1.f - $3.f;
}
;

comparison_expression
: additive_expression {if ($1.t.element_type == INT_T)
     $$.n =  $1.n;
     else if ($1.t.element_type == FLOAT_T)
       $$.f = $1.f;}
| additive_expression '<' additive_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      $$.n = ($1.n < $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n < $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f < $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f < $3.f);
}
| additive_expression '>' additive_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      $$.n = ($1.n > $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n > $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f > $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f > $3.f);
}
| additive_expression LE_OP additive_expression
{if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
    $$.n = ($1.n >= $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n >= $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f >= $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f >= $3.f);
}
| additive_expression GE_OP additive_expression
{if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
    $$.n = ($1.n <= $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n <= $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f <= $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f <= $3.f);
}
| additive_expression EQ_OP additive_expression
{if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
    $$.n = ($1.n == $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n == $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f == $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f == $3.f);
}
| additive_expression NE_OP additive_expression
{if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
    $$.n = ($1.n != $3.n);
   else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.n != $3.f);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
     $$.f = ($1.f != $3.n);
   else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
     $$.f = ($1.f != $3.f);
}
;

expression
: IDENTIFIER '=' comparison_expression {if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
     ($1.n = $3.n);
 else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
   perror("int = float not allowed");
 else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
   ($1.f = $3.n);
 else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
   ($1.f = $3.f); }
| IDENTIFIER '[' expression ']' '=' comparison_expression 
{if($3.t.element_type == INT_T){
    if (($1.t.element_type == INT_T)&&($3.t.element_type == INT_T))
      ($1[$3.n].n = $6.n);
    else if (($1.t.element_type == INT_T)&&($3.t.element_type == FLOAT_T))
      perror("int[int] = float not allowed"); exit(0);
    else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == INT_T))
      ($1[$3.n].f = $6.n);
    else if (($1.t.element_type == FLOAT_T)&&($3.t.element_type == FLOAT_T))
   ($1[$3.n].f = $6.f);
  }
  else
    {
      perror("expression not an int"); exit(0);
    }
} 
| comparison_expression {if ($1.t.element_type == INT_T)
     $$.n =  $1.n;
     else if ($1.t.element_type == FLOAT_T)
       $$.f = $1.f;}
;

declaration
: type_name declarator_list ';'
;

declarator_list
: declarator {$$[0] = $1 ; dliste =1;}
| declarator_list ',' declarator {$$[dliste++] = $3;}
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
: declaration {$$[0] = $1; dliste = 1;}
| declaration_list declaration {}
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
: IF '(' expression ')' statement {$$ = if ($3) $5;}
| IF '(' expression ')' statement ELSE statement {$$ = if ($3) $5; else $7;}
;

iteration_statement
: WHILE '(' expression ')' statement {$$ = while ($3) $5;)} 
| FOR '(' expression_statement expression_statement expression ')' statement {$$ = for($3) $5;}
| DO  statement  WHILE '(' expression ')' ';' {$$ = do $2; while ($5)}
;

jump_statement
: RETURN ';' {return ;}
| RETURN expression ';' {return $2;}
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
