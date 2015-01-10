%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "type.h"
    extern int yylineno;
    int bt;
    int nliste = 0;
    int dliste = 0;
    int sliste = 0;
    int pliste = 0;
    int level = 0;
    int yylex ();
    int yyerror ();
    int addr = 0;
    int nlabel = 0;

%}

%token <t> IDENTIFIER 
%token <n> ICONSTANT 
%token <f> FCONSTANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR DO
%type <t> declarator
%type <t> parameter_declaration
%type <t> expression
%type <t> unary_expression
%type <t> primary_expression
%type <t> additive_expression
%type <t> multiplicative_expression
%type <t> comparison_expression
%type <t> declaration
%type <t> compound_statement
%type <t> selection_statement
%type <t> expression_statement
%type <t> iteration_statement
%type <t> statement
%type <lt> declarator_list
%type <lt> declaration_list
%type <lt> statement_list
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
: IDENTIFIER {printf("pushl $%%rbp\n");}
| ICONSTANT {printf("pushl $%d\n",$1); }
| FCONSTANT {printf("pushl $%f\n",$1); }
| '(' expression ')' {$$.element_type = $2.element_type;}
| IDENTIFIER '(' ')' {$$.element_type = $1.element_type;} 
| IDENTIFIER '(' argument_expression_list ')' {$$.element_type = $1.element_type;}
| IDENTIFIER INC_OP {$$.element_type = $1.element_type; printf("addl $1 -%d(%%rbp)\n",$1.addre);}
| IDENTIFIER DEC_OP {$$.element_type = $1.element_type; printf("subl $1 -%d(%%rbp)\n",$1.addre);}
| IDENTIFIER '[' expression ']' {$$.element_type = $1.element_type; if($1.element_type == INT_T) 
								      {printf("popl %%eax\nsubl $%d %%eax\naddl %%eax %%rbp\npushl [%%eax]\n",$1.addre*4);}} /* A revoir au plus vite !*/ 
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: primary_expression {if ($1.element_type == INT_T)
     $$.element_type = INT_T;
     //$$.no =  $1.no;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = $1.fo;
 }
| '-' unary_expression {if ($2.element_type == INT_T)
      {  $$.element_type = INT_T;
	printf("popl %%eax\nneg %%eax\npushl %%eax\n");
      }
      //$$.no = - $2.no;
     else if ($2.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = - $2.fo;
  }
| '!' unary_expression {if ($2.element_type == INT_T)
      {   $$.element_type = INT_T;
	printf("popl %%eax\ncmpl $0, %%eax\njne L%d\npushl $1\njmp L%d\nL%d:\npushl $0\nL%d:\n",nlabel,nlabel+1,nlabel,nlabel+1); // Y a peut-etre besoin de mettre un . devant les labels...
	nlabel += 2;
  }
     else if ($2.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = (! $2.fo);
  }
;

multiplicative_expression
: unary_expression {if ($1.element_type == INT_T)
     $$.element_type = INT_T;
     //$$.no =  $1.no;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = $1.fo;
 }
| multiplicative_expression '*' unary_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T)) 
      {
	$$.element_type = INT_T;
	printf("popl %%eax\npopl %%ebx\nimul %%ebx, %%eax\npushl %%eax\n");
      }
      // $$.no = $1.no + $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       printf("popl %%eax\npopl %%ebx\nfmul %%ebx, %%eax\npushl %%eax\n");  // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
     $$.element_type = FLOAT_T;
     printf("popl %%eax\npopl %%ebx\nfmul %%ebx, %%eax\npushl %%eax\n");  // On doit convertir le int en float avant
     }
     // $$.fo = $1.fo + $3.no;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       printf("popl %%eax\npopl %%ebx\nfmul %%ebx, %%eax\npushl %%eax\n");
     }
}
;

additive_expression
: multiplicative_expression {if ($1.element_type == INT_T)
     $$.element_type = INT_T;
     //$$.no =  $1.no;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = $1.fo;
       }
| additive_expression '+' multiplicative_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      {
	$$.element_type = INT_T;
	printf("popl %%eax\npopl %%ebx\naddl %%ebx, %%eax\npushl %%eax\n");
      }
      // $$.no = $1.no + $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       printf("popl %%eax\npopl %%ebx\naddss %%ebx, %%eax\npushl %%eax\n"); // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
     $$.element_type = FLOAT_T;
     printf("popl %%eax\npopl %%ebx\naddl %%ebx, %%eax\npushl %%eax\n"); // ici aussi
     }
     // $$.fo = $1.fo + $3.no;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       printf("popl %%eax\npopl %%ebx\naddss %%ebx, %%eax\npushl %%eax\n");
     }
     //$$.fo = $1.fo + $3.fo;
}
| additive_expression '-' multiplicative_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      {
      $$.element_type = INT_T;
      printf("popl %%eax\npopl %%ebx\nsubl %%ebx, %%eax\npushl %%eax\n");
      }
      // $$.no = $1.no - $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       //printf("popl %%eax\npopl %%ebx\nsubl %%ebx, %%eax\npushl %%eax\n"); // On doit convertir le int en float avant
       //$$.fo = $1.no - $3.fo;
     }
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
       $$.element_type = FLOAT_T;
       //printf("popl %%eax\npopl %%ebx\nsubl %%ebx, %%eax\npushl %%eax\n");  // On doit convertir le int en float avant
       //$$.fo = $1.fo - $3.no;
     }
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       printf("popl %%eax\npopl %%ebx\nsubss %%ebx, %%eax\npushl %%eax\n");
     }
     //$$.fo = $1.fo - $3.fo;
}
;

comparison_expression
: additive_expression {if ($1.element_type == INT_T)
      {$$.element_type = INT_T;
      }
     //$$.no =  $1.no;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = $1.fo;
       }
| additive_expression '<' additive_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      $$.element_type = INT_T;
      //$$.no = ($1.no < $3.no);
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.no < $3.fo);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.fo < $3.no);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.fo < $3.fo);
}
| additive_expression '>' additive_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      $$.element_type = INT_T;
      //$$.no = ($1.no > $3.no);
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.no > $3.fo);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.fo > $3.no);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.fo = ($1.fo > $3.fo);
}
| additive_expression LE_OP additive_expression
{if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    $$.element_type = INT_T;
    //$$.n = ($1.n >= $3.n);
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.n >= $3.f);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f >= $3.n);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f >= $3.f);
}
| additive_expression GE_OP additive_expression
{if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    $$.element_type = INT_T;
    //$$.n = ($1.n <= $3.n);
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.n <= $3.f);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f <= $3.n);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     // $$.f = ($1.f <= $3.f);
}
| additive_expression EQ_OP additive_expression
{if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    $$.element_type = INT_T;
    //$$.n = ($1.n == $3.n);
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.n == $3.f);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     // $$.f = ($1.f == $3.n);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f == $3.f);
}
| additive_expression NE_OP additive_expression
{if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    $$.element_type = INT_T;
  //$$.n = ($1.n != $3.n);
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
    $$.element_type = FLOAT_T;
    //$$.f = ($1.n != $3.f);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f != $3.n);
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     $$.element_type = FLOAT_T;
     //$$.f = ($1.f != $3.f);
}
;

expression
: IDENTIFIER '=' comparison_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T)){
     $$.element_type = INT_T;
     //($1.n = $3.n);
     printf("popl %%eax\nmovl %%eax -%d(%%rbp)\npushl %%eax\n",$1.addre);
   }
 else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
   perror("int = float not allowed");
 else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
   $$.element_type = FLOAT_T;
   //($1.f = $3.n);
 else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
   $$.element_type = FLOAT_T;
   //($1.f = $3.f); 
   printf("popl %%eax\nmovl %%eax -%d(%%rbp)\npushl %%eax\n",$1.addre);
 }
}
| IDENTIFIER '[' expression ']' '=' comparison_expression 
{if($3.element_type == INT_T){
    if (($1.element_type == INT_T)&&($3.element_type == INT_T)){
      $$.element_type = INT_T;
      //($1[$3.n].n = $6.n);
      printf("popl %%eax\npopl %%ebx\nimul $4 %%ebx\nsubl %d %%ebx\nmovl %%eax %%rbp\n",$1.addre);
    }
    else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
      {perror("int[int] = float not allowed"); exit(0);}
    else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
      $$.element_type = FLOAT_T;
      //($1[$3.n].f = $6.n);
    else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
      $$.element_type = FLOAT_T;
      //($1[$3.n].f = $6.f);
  }
  else
    {
      perror("expression not an int"); exit(0);
    }
} 
| comparison_expression {if ($1.element_type == INT_T)
      $$.element_type = INT_T;
      //$$.n =  $1.n;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.f = $1.f;
}
;

declaration
: type_name declarator_list ';' 
;

declarator_list
: declarator {$$[0].element_type = $1.element_type ; dliste =1;}
| declarator_list ',' declarator {$$[dliste++].element_type = $3.element_type;}
;

type_name
: VOID  {bt = VOID_T;}
| INT  {bt = INT_T;}
| FLOAT {bt = FLOAT_T;}
; 

declarator
: IDENTIFIER  { 
  if (bt != VOID_T){ 
      addr += 4; $$.addre += addr;
  }
  $$.element_type = bt; $$.kind = -1 ;}
| '*' IDENTIFIER { 
  if(bt == VOID_T)
 {
     perror("void* not allowed"); exit(0);
 } 
  else
    {
      addr += 8;
      $$.addre += addr;
      $$.element_type = bt+1 ; 
      $$.kind = -1;
    }
}
| IDENTIFIER '[' ICONSTANT ']' {$$.element_type = bt; $$.kind = 0;
   $$.element_size = $3; addr += 4*$3 ; $$.addre = addr;}
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
: declaration {$$[0] = $1; pliste = 1;}
| declaration_list declaration {$$[pliste++] = $2;}
;

statement_list
: statement {$$[0] = $1; sliste = 1;}
| statement_list statement {$$[pliste++] = $2;}
;

expression_statement
: ';' 
| expression ';' {$$.element_type = $1.element_type;}
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
