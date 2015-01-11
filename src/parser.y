%{
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include "type.h"
    using namespace std;
    extern int yylineno;
    int yyerror (const char *error);
    void printCode (vector<std::string*> vec);
    int  yylex ();
    type bt;
    int nliste = 0;
    int dliste = 0;
    int sliste = 0;
    int pliste = 0;
    int level = 0;
    int yylex ();
    int yyerror ();
    int addr = 0;
    int nlabel = 0;
    int nfunc = 0;
    vector<std::string*> vec;

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
%type <t> jump_statement
%type <t> function_definition
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
: IDENTIFIER {$$.code = new std::string("pushq %%rbp\n");vec.push_back($$.code); $$.addre = $1.addre;}
| ICONSTANT {std::stringstream s; s << "pushq $" << $1 << "\n";$$.code = new std::string(s.str());vec.push_back($$.code);}
| FCONSTANT {std::stringstream s; s << "pushq $" << $1 << "\n";$$.code = new std::string(s.str());vec.push_back($$.code);}
| '(' expression ')' {$$.element_type = $2.element_type;}
| IDENTIFIER '(' ')' {$$.element_type = $1.element_type; $$.addre = $1.addre;} 
| IDENTIFIER '(' argument_expression_list ')' {$$.element_type = $1.element_type; $$.addre = $1.addre;}
| IDENTIFIER INC_OP {
 $$.element_type = $1.element_type;
 std::stringstream s;
 s << "addq $1 " << -$1.addre << "(%%rbp)\npushq " << -$1.addre << "(%%rbp)\n";
 $$.code = new std::string(s.str());
 vec.push_back($$.code);
 $$.addre = $1.addre;
 }
| IDENTIFIER DEC_OP {
 $$.element_type = $1.element_type;
 std::stringstream s;
 s << "subq $1 " << -$1.addre << "(%%rbp)\npushq " << -$1.addre << "(%%rbp)\n";
 $$.code = new std::string(s.str());
 vec.push_back($$.code);
 $$.addre = $1.addre;
}
| IDENTIFIER '[' expression ']' {
$$.element_type = $1.element_type; 
if($1.element_type == INT_T) {
std::stringstream s;
s << "popq %%rax\nmovq " << -$1.addre << "(%%rbp, %%rax, 8), %%rax\npushq %%rax\n";
$$.code = new std::string(s.str());
vec.push_back($$.code);
}
}
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
   $$.addre = $1.addre;
 }
| '-' unary_expression {if ($2.element_type == INT_T)
      { $$.element_type = INT_T;
		$$.code = new std::string("popq %%rax\nneg %%rax\npushq %%rax\n");
		vec.push_back($$.code);
      }
      //$$.no = - $2.no;
     else if ($2.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = - $2.fo;
   $$.addre = $2.addre;
  }
| '!' unary_expression {if ($2.element_type == INT_T)
		{   
		  $$.element_type = INT_T;
		  std::stringstream s;
		  s << "popq %%rax\ncmpq $0, %%rax\njne L" << nlabel << "\npushq $1\njmp L" << (nlabel+1) << "\n.L" << nlabel << ":\npushq $0\n.L"<<(nlabel+1)<<":\n";
		  $$.code = new std::string(s.str());
		  vec.push_back($$.code); 
		  nlabel += 2;
		 }
     else if ($2.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = (! $2.fo);
   $$.addre = $2.addre;
  }
;

multiplicative_expression
: unary_expression {if ($1.element_type == INT_T)
     $$.element_type = INT_T;
     //$$.no =  $1.no;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.fo = $1.fo;
   $$.addre = $1.addre;
 }
| multiplicative_expression '*' unary_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T)) 
      {
	  $$.element_type = INT_T;
	  $$.code = new std::string("popq %%rax\npopq %%rbx\nimul %%rbx, %%rax\npushq %%rax\n");
	  vec.push_back($$.code);
      }
      // $$.no = $1.no + $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
     $$.element_type = FLOAT_T;
     $$.code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back($$.code);  // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
     $$.element_type = FLOAT_T;
     $$.code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back($$.code);   // On doit convertir le int en float avant
     }
     // $$.fo = $1.fo + $3.no;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
     $$.element_type = FLOAT_T;
     $$.code = new std::string("popq %%rax\npopq %%rbx\nfmul %%rbx, %%rax\npushq %%rax\n");
	 vec.push_back($$.code);   // On doit convertir le int en float avant
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
   $$.addre = $1.addre;
       }
| additive_expression '+' multiplicative_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      {
		$$.element_type = INT_T;
		$$.code = new std::string("popq %%rax\npopq %%rbx\naddq %%rbx, %%rax\npushq %%rax\n");
		vec.push_back($$.code);
      }
      // $$.no = $1.no + $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\naddss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code); // On doit convertir le int en float avant
     }
       // $$.fo = $1.no + $3.fo;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
	   $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\naddq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code); // ici aussi
     }
     // $$.fo = $1.fo + $3.no;
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\naddss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code);
     }
     //$$.fo = $1.fo + $3.fo;
}
| additive_expression '-' multiplicative_expression {if (($1.element_type == INT_T)&&($3.element_type == INT_T))
      {
       $$.element_type = INT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code);
      }
      // $$.no = $1.no - $3.no;
   else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code); // On doit convertir le int en float avant
       //$$.fo = $1.no - $3.fo;
     }
   else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
     {
       $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\nsubq %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code);  // On doit convertir le int en float avant
       //$$.fo = $1.fo - $3.no;
     }
   else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
     {
       $$.element_type = FLOAT_T;
       $$.code = new std::string("popq %%rax\npopq %%rbx\nsubss %%rbx, %%rax\npushq %%rax\n");
	   vec.push_back($$.code);
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
   $$.addre = $1.addre;
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
     std::stringstream s;
	 s << "popq %%rax\nmovl %%rax " << -$1.addre << "(%%rbp)\npushq %%rax\n";
	 $$.code = new std::string(s.str());
	 vec.push_back($$.code);
   }
 else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
   perror("int = float not allowed");
 else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
   $$.element_type = FLOAT_T;
   //($1.f = $3.n);
 else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
   $$.element_type = FLOAT_T;
   //($1.f = $3.f);
   std::stringstream s;
   s << "popq %%rax\nmovl %%rax " << -$1.addre << "(%%rbp)\npushq %%rax\n";
   $$.code = new std::string(s.str());
   vec.push_back($$.code);
 }
   $$.addre = $1.addre;
}
| IDENTIFIER '[' expression ']' '=' comparison_expression 
{if($3.element_type == INT_T){
    if (($1.element_type == INT_T)&&($3.element_type == INT_T)){
      $$.element_type = INT_T;
      //($1[$3.n].n = $6.n);
	  std::stringstream s;
	  s << "popq %%rax\npopq %%rbx\nmovq %%rax, " << -$1.addre << "(%%rbp, %%rbx, 8)\npushq %%rax\n";
	  $$.code = new std::string(s.str());
	  vec.push_back($$.code);
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
  $$.addre = $1.addre;
} 
| comparison_expression {if ($1.element_type == INT_T)
      $$.element_type = INT_T;
      //$$.n =  $1.n;
     else if ($1.element_type == FLOAT_T)
       $$.element_type = FLOAT_T;
       //$$.f = $1.f;
   $$.addre = $1.addre;
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
      addr += 8; $1.addre += addr;
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
      $2.addre += addr;
      $$.element_type = (type)(bt+1); 
      $$.kind = -1;
    }
}
| IDENTIFIER '[' ICONSTANT ']' {$$.element_type = bt; $$.kind = 0;
   $$.element_size = $3; addr += 8*$3 ; $$.addre = addr;}
| declarator '(' parameter_list ')' {addr = 0;$$.element_type = bt; $$.kind = 1; 
$$.element_size = nliste; $$.function_parameters = $3;} 
| declarator '(' ')' {
	addr = 0;
	$$.element_type = bt;
	$$.kind = 1;
	$$.element_size = 0;	
	std::stringstream s;
	s << "main:\n.LFB" << nfunc << ":\n.cfi_startproc\npushq	%%rbp\n";
	s << ".cfi_def_cfa_offset 16\n.cfi_offset 6, -16\nmovq	%%rsp, %%rbp\n.cfi_def_cfa_register 6\n";
	$$.code = new std::string(s.str());
	vec.push_back($$.code);
 }
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
| expression ';' {
 $$.element_type = $1.element_type;
 $$.code = new std::string("popq %%rax\n");
 vec.push_back($$.code);
 }
;
//{printf("popq %%rax\ncmpl $0, %%rax\njne L%d\npushq $1\njmp L%d\nL%d:\npushq $0\nL%d:\n",nlabel,nlabel+1,nlabel,nlabel+1); }
selection_statement
: IF '(' expression ')' statement {}  
| IF '(' expression ')' statement ELSE statement 
;

iteration_statement
: WHILE '(' expression ')' statement 
| FOR '(' expression_statement expression_statement expression ')' statement 
| DO  statement  WHILE '(' expression ')' ';' 
;

jump_statement
: RETURN ';' {
 std::string s("movl $1, -8(%%rbp)\n");
 $$.code = new std::string(s);
 vec.push_back($$.code);
 printCode(vec);
}
| RETURN expression ';' {
 std::stringstream s;
 s << "popq %%rax\nmovl %%rax, " << -$2.addre << "(%%rbp)\n";
 $$.code = new std::string(s.str());
 vec.push_back($$.code);
 printCode(vec);
}
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
: type_name declarator compound_statement {
 std::stringstream s;
 s << ".cfi_def_cfa 7, 8\nret\n.cfi_endproc\n.LFE" << nfunc << ":\n";
 $$.code = new std::string(s.str());
 vec.push_back($$.code);
 nfunc++;
 }
;

%%
#include <cstdio>
#include <string>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (const char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}

void printCode (vector<std::string*> vec) {
	
	for (std::string* i : vec)
	{
		std::cout << *i;
		delete(i);
	}
	vec.clear();
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
    printf(".file	\"%s\"\n.text\n",argv[1]);
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
