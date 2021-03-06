%{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include<map>
#include "type.h"
  using namespace std;
  extern int yylineno;
  int yyerror (const char *error);
  void printCode (std::string* code);
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
  int nfunc = 2;
  string current_function;
  vector<std::string*> vec;
  map<std::string, type_t> VariableStack;
  map<std::string, type_t> ParameterStack; //pour comparer à l'appel
  map<std::string, type_t> temp_param_stack; //pour la déclaration
  vector<type_t> temp_appel_param_stack; //pour l'appel
  %}

%token <str> IDENTIFIER 
%token <n> ICONSTANT 
%token <f> FCONSTANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR DO
%type <t> program
%type <t> external_declaration
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
%type <t> argument_expression_list
%type <t> declarator_list
%type <t> declaration_list
%type <t> statement_list
%type <t> parameter_list
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
: IDENTIFIER {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier;
  $$.code = new std::string("pushq %rbp\n");
  vec.push_back($$.code);
 }
| ICONSTANT {
  std::stringstream s;
  s << "pushq $" << $1 << "\n";
  $$.code = new std::string(s.str());
  $$.element_type = INT_T;
  $$.kind = -1;
  vec.push_back($$.code);
  }
| FCONSTANT {
  std::stringstream s;
  s << "pushq $" << $1 << "\n";
  $$.code = new std::string(s.str());
  $$.element_type = FLOAT_T;
  $$.kind = -1;
  vec.push_back($$.code);
  }
| '(' expression ')' {
  $$ = $2;
  }
| IDENTIFIER '(' ')' {
  type_t local_identifier = VariableStack[$1];
  $$ = local_identifier;
    if($$.kind != 1)
	{
		perror("Invalid Operation");
		exit(EXIT_FAILURE);
	}
  std::stringstream s;
  s << "call " << $1 << "\n";
  $$.code = new std::string(s.str());
  } 
| IDENTIFIER '(' argument_expression_list ')' {
  type_t local_identifier = VariableStack[$1];
  $$ = local_identifier;
  if($$.kind != 1)
	{
		perror("Invalid Operation");
		exit(EXIT_FAILURE);
	}
  for (int i = 0; i<$$.element_size; i++)
  {
		  
  }	
  std::stringstream s;
  s << "call " << $1 << "\n";
  $$.code = new std::string(s.str());
  }

| IDENTIFIER INC_OP {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier;
  std::stringstream s;
  if(local_identifier.element_type == INT_T){
    s << "addq $1, ";
    s << -local_identifier.addre;
    s << "(%rbp)\npushq ";
    s << -local_identifier.addre;
    s << "(%rbp)\n";
  }
  else if (local_identifier.element_type == FLOAT_T){
    s << "fld1\n";
    s << "fstp DWORD %xmm0\n";
    //s << "fld st0\n";
    //s << "movss st0, %xmm0\n";
    /*s << "movss ";
      s << -local_identifier.addre;
      s << "(%rbp)";
      s << ", %xmm1\n";*/
    s << "fstp QWORD %xmm1\n";
    s << "addss %xmm0, %xmm1\n";
    /*s << "movss %xmm1, ";
      s << -local_identifier.addre;
      s << "(%rbp)\n";
      s << "pushq ";
      s << -local_identifier.addre;
      s << "(%rbp)\n";*/
    s << "fld QWORD %xmm1\n" ;
  }
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
| IDENTIFIER DEC_OP {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier;
  std::stringstream s;
  if(local_identifier.element_type == INT_T){

    s << "subq $1, " ;
    s << -local_identifier.addre;
    s << "(%rbp)\npushq ";
    s << -local_identifier.addre;
    s << "(%rbp)\n";
  }
  else if(local_identifier.element_type == FLOAT_T){
    s << "fld1\n";
    s << "fstp QWORD %xmm0\n";
    //s << "movq $1, %rax\n";
    //s << "movss st0, %xmm0\n";
    /*s << "movss ";
      s << -local_identifier.addre;
      s << "(%rbp)";*/
    s << "fstp QWORD %xmm1\n";
    //s << ", %xmm1\n";
    s << "subss %xmm0, %xmm1\n";
    /*s << "movss %xmm1, ";
      s << -local_identifier.addre;
      s << "(%rbp)\n";*/
    /*s << "pushq ";
      s << -local_identifier.addre;
      s << "(%rbp)\n";*/
    s << "fld QWORD %xmm1\n";
  }
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
| IDENTIFIER '[' expression ']' {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier; 
  if(local_identifier.element_type == INT_T) {
    std::stringstream s;
    s << *$3.code;
    s << "popq %rax\nmovq ";
    s << -local_identifier.addre;
    s << "(%rbp, %rax, 8), %rax\npushq %rax\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
  }
  }
;

argument_expression_list
: expression { $$ = $1; temp_appel_param_stack.push_back($1); }
| argument_expression_list ',' expression { 
  $$ = $3;
  std::stringstream s;
  s << *$1.code;
  s << *$3.code;
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  temp_appel_param_stack.push_back($3);	
 }
;

unary_expression
: primary_expression {
  $$ = $1;
 }
| '-' unary_expression {
  $$ = $2;	
  if ($2.element_type == INT_T)
    { 
      std::stringstream s;
      s << *$2.code;
      s << "popq %rax\n";
      s << "neg %rax\npushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if ($2.element_type == FLOAT_T){
    std::stringstream s;
    s << *$2.code;
    s << "fstp QWORD %xmm0\n"; 
    //s << "popq %rax\n";
    s << "negss %xmm0\n";
    //s << "pushq %rax\n";
    s << "fld QWORD %xmm0\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
  }
  }
| '!' unary_expression {
  $$ = $2;
  if ($2.element_type == INT_T)
    {   
      std::stringstream s;
      s << *$2.code;
      s << "popq %rax\n";
      s << "cmpq $0, %rax\n";
      s << "jne L" << nlabel << "\n";
      s << "pushq $1\n";
      s << "jmp L" << (nlabel+1) << "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $0\n";
      s << ".L"<< (nlabel+1) <<":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code); 
      nlabel += 2;
    }
  else if ($2.element_type == FLOAT_T){
    std::stringstream s;
    s << *$2.code;
    /*s << "popq %rax\n";
      s << "movq $0, %rbx\n\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fldz\n";
    s << "fstp QWORD %xmm0";
    s << "fstp QWORD %xmm1";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jne L" << nlabel << "\n";
    s << "fld1\n";
    s << "jmp L" << (nlabel+1) << "\n";
    s << ".L" << nlabel << ":\n";
    s << "fldz\n";
    s << ".L"<< (nlabel+1) <<":\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code); 
    nlabel += 2;
  }
  }
;

multiplicative_expression
: unary_expression {
  $$ = $1;
 }
| multiplicative_expression '*' unary_expression {
  $$ = $1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T)) 
    {
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "imul %rbx, %rax\n";
      s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      //s << "popq %rbx\n";
      s << "fild QWORD %rax\n";
      s << "fstp QWORD %xmm0\n";
      //s << "movss %rbx, %xmm0\n";
      s << "fstp QWORD %xmm1\n"; 
      s << "mulss %xmm0, %xmm1\n";
      //s << "movss %xmm1, %rax\n";
      s << "fld QWORD %xmm1\n";
      //s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = FLOAT_T;
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      //s << "popq %rax\n";
      s << "popq %rax\n";
      s << "fild QWORD %rax";
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n"; 
      /*s << "movss %rbx, %xmm0\n";
	s << "movss %rax, %xmm1\n";*/
      s << "mulss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n";
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      /*s << "popq %rax\n";
	s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n";
      s << "mulss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n" ;
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  }
;

additive_expression
: multiplicative_expression {
  $$ = $1;
 }
| additive_expression '+' multiplicative_expression {
  $$ = $1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "addq %rbx, %rax\n";
      s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      /*s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fild QWORD %rax\n";
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n";
      s << "addss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n" ;
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      /*s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fild QWORD %rax\n";
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n" ;
      s << "addss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      /*s << "popq %rax\n";
	s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fstp QWORD %xmm1\n";
      s << "fstp QWORD %xmm0\n";
      s << "addss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  }
| additive_expression '-' multiplicative_expression {
  $$ = $1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "subq %rbx, %rax\n";
      s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "fild QWORD %rax\n" ;
      /*s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n";
      s << "subss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "fild QWORD %rax\n";
      /*s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fstp QWORD %xmm1\n";
      s << "fstp QWORD %xmm0\n";
      s << "subss %xmm0, %xmm1\n";
      /*s << "movss %xmm1, %rax\n";
	s << "pushq %rax\n";*/
      s << "fld QWORD %xmm1\n" ;
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      /*s << "popq %rax\n";
	s << "popq %rbx\n";
	s << "movss %rax, %xmm0\n";
	s << "movss %rbx, %xmm1\n";*/
      s << "fstp QWORD %xmm0\n";
      s << "fstp QWORD %xmm1\n";
      s << "subss %xmm0, %xmm1\n";
      //s << "movss %xmm1, %rax\n";
      //s << "pushq %rax\n";
      s << "fld QWORD %xmm1\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  }
;

comparison_expression
: additive_expression {
  $$=$1;
 }
| additive_expression '<' additive_expression {
  $$=$1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "jl .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jl .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jl .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jl .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  }
| additive_expression '>' additive_expression {
  $$=$1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    {
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "jg .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jg .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jg .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jg .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  }
| additive_expression LE_OP additive_expression
{	$$ = $1;	
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    { $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "jle .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jle .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jle .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jle .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
}
| additive_expression GE_OP additive_expression
{	$$=$1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    { $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "jge .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jge .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jge .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jge .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
}
| additive_expression EQ_OP additive_expression
{	$$=$1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    { $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "je .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "je .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "je .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "je .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
}
| additive_expression NE_OP additive_expression
{	$$=$1;
  if (($1.element_type == INT_T)&&($3.element_type == INT_T))
    { $$.element_type = INT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "cmp %rax, %rbx\n";
      s << "jne .L" << nlabel << "\n";
      s << "movq $1, %rbp\n";
      s << ".L" << nlabel << ":\n";
      s << "movq $0, %rbp\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel++;
    }
  else if (($1.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n";
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jne .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n" ;
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n" ;
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    s << "popq %rax\n";
    /*s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fild QWORD %rax\n" ;
    s << "fstp QWORD %xmm1\n";
    s << "fstp QWORD %xmm0\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jne .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
    $$.element_type = FLOAT_T;
    std::stringstream s;
    s << *$1.code;
    s << *$3.code;
    /*s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movss %rax, %xmm0\n";
      s << "movss %rbx, %xmm1\n";*/
    s << "fstp QWORD %xmm0\n";
    s << "fstp QWORD %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jne .L" << nlabel << "\n";
    //s << "movq $1, %rbp\n";
    s << "fld1\n";
    s << ".L" << nlabel << ":\n";
    //s << "movq $0, %rbp\n";
    s << "fldz\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel++;
  }
}
;

expression
: IDENTIFIER '=' comparison_expression {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier;
  if($$.kind != -1){
  perror("invalid operation");
  exit(EXIT_FAILURE);
  }
  else if ((local_identifier.element_type == INT_T)&&($3.element_type == INT_T)){
    std::stringstream s;
    s << *$3.code;
    s << "popq %rax\n";
    s << "movq %rax, " << -local_identifier.addre << "(%rbp)\n";
    s << "pushq %rax\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
  }
  else if ((local_identifier.element_type == INT_T)&&($3.element_type == FLOAT_T)){
    perror("int = float not allowed");}
  else if ((local_identifier.element_type == FLOAT_T)&&($3.element_type == INT_T)){
    $$.element_type = FLOAT_T;} // idem pour float
  else if ((local_identifier.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){ //idem pour float
    std::stringstream s;
    s << "popq %rax\nmovq %rax " << -local_identifier.addre << "(%rbp)\npushq %rax\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
  }
  else if(local_identifier.element_type == INTSTAR_T || local_identifier.element_type == FLOATSTAR_T) 
  {
	 if($3.element_type == local_identifier.element_type && $3.kind == -1) // egalite entre pointeurs
	 {
	    std::stringstream s;
		s << *$3.code;
		s << "popq %rax\n";
		s << "movq %rax, " << -local_identifier.addre << "(%rbp)\n";
		s << "pushq %rax\n";
		$$.code = new std::string(s.str());
		vec.push_back($$.code);
	 }
	 else if(($3.kind = 0) && ($3.element_type == local_identifier.element_type + 1)) //pointeur egal vecteur
	 {
	  std::stringstream s;
	  s << "popq %rax\nmovq %rax " << -local_identifier.addre << "(%rbp)\npushq %rax\n";
	  $$.code = new std::string(s.str());
	  vec.push_back($$.code);
	 }
	 else
	 {
	 
		perror("invalid operation");
		exit(EXIT_FAILURE);
	 
	 }
  }
  $$.addre = local_identifier.addre;
 }
| IDENTIFIER '[' expression ']' '=' comparison_expression 
{	
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier;
  if($3.element_type == INT_T){
    if ((local_identifier.element_type == INT_T)&&($3.element_type == INT_T)){
      $$.element_type = INT_T;
      std::stringstream s;
      s << *$3.code;
      s << *$6.code;
      s << "popq %rax\n";
      s << "popq %rbx\n";
      s << "movq %rax, " << -local_identifier.addre << "(%rbp, %rbx, 8)\n";
      s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
    else if ((local_identifier.element_type == INT_T)&&($3.element_type == FLOAT_T))
      {perror("int[int] = float not allowed"); exit(0);}
    else if ((local_identifier.element_type == FLOAT_T)&&($3.element_type == INT_T))
      $$.element_type = FLOAT_T;
    else if ((local_identifier.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
      $$.element_type = FLOAT_T;
  }
  else
    {
      perror("expression not an int"); exit(0);
    }
  $$.addre = local_identifier.addre;
} 
| comparison_expression {
  $$ = $1;
  }
;

declaration
: type_name declarator_list ';' { $$ = $2;}
;

declarator_list
: declarator {$$ = $1 ;}
| declarator_list ',' declarator {
  $$ = $3;
  std::stringstream s;
  s << *$1.code;
  s << *$3.code;
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  }
;

type_name
: VOID  {bt = VOID_T;}
| INT  {bt = INT_T;}
| FLOAT {bt = FLOAT_T;}
; 

declarator
: IDENTIFIER  { 
  if(current_function != "") //variable
  {
	  if (bt != VOID_T){ 
		addr += 8; $$.addre = addr;
	  }
	  $$.element_type = bt;
	  $$.kind = -1 ;
	  $$.code = new std::string("");
	  vec.push_back($$.code);
	  VariableStack.insert ( std::pair<std::string, type_t>(current_function +" "+$1,$$) );
		}
	else {  //parametre de fonction
  
  	  $$.element_type = bt;
	  $$.kind = -1 ;
	  $$.code = new std::string("");
	  vec.push_back($$.code);
      temp_param_stack.insert(std::pair<std::string, type_t>($1,$$));
  }
 }
| '*' IDENTIFIER { 
  if(current_function != "") //variable
  {
	  if(bt == VOID_T)
		{
		  perror("void* not allowed"); exit(0);
		} 
	  else
		{
		  addr += 8;
		  $$.addre = addr;
		  $$.element_type = (type)(bt+1); 
		  $$.kind = -1;
		  $$.code = new std::string("");
		  vec.push_back($$.code);
		  VariableStack.insert ( std::pair<std::string, type_t>(current_function +" "+$2,$$) );
		}
	}
	else {  //parametre de fonction
  
  		$$.addre = addr;
  		$$.element_type = (type)(bt+1); 
		$$.kind = -1;
  		$$.code = new std::string("");
		vec.push_back($$.code);
		temp_param_stack.insert(std::pair<std::string, type_t>($2,$$));
  }
  }
| IDENTIFIER '[' ICONSTANT ']' {
  if(current_function != "") //variable
  {
	  $$.element_type = bt; 
	  $$.kind = 0;
	  $$.element_size = $3; 
	  addr += 8*$3 ; 
	  $$.addre = addr; 
	  $$.code = new std::string(""); 
	  vec.push_back($$.code); 
	  VariableStack.insert( std::pair<std::string, type_t>(current_function +" "+$1,$$) );
  }
  else {  //parametre de fonction
  
	perror("array can't be given as a parameter");
	exit(EXIT_FAILURE);
  }
 }
| IDENTIFIER '(' parameter_list ')' {
  if(current_function != "")
  {
	perror("A function cannot be defined inside another");
	exit(EXIT_FAILURE);
  }
  addr = 0;
  $$.element_type = bt; 
  $$.kind = 1; 
  $$.element_size = temp_param_stack.size();
  $$.code = new std::string("");
  vec.push_back($$.code);
  //$$.function_parameters = $3; 
  VariableStack.insert(std::pair<std::string, type_t>($1, $$)); 
  int i = 0;
  std::stringstream ss;
  std::stringstream ss2;
  for(map<std::string, type_t>::iterator it=temp_param_stack.begin() ; it!=temp_param_stack.end() ; ++it)
  {
  	  ss << $1;
	  ss << " ";
	  ss << it->first;
	  VariableStack.insert(std::pair<std::string, type_t>(ss.str(),it->second)); //on le stock comme une variable normale pour y acceder dans la fonction concernee
	  ss2 << $1;
	  ss2 <<" ";
	  ss2 << i;
	  ParameterStack.insert(std::pair<std::string, type_t>(ss.str(),it->second)); //on duplique pour pouvoir rechercher les parametres facilement hors de la fonction
	  i++;
  }
  vec.clear();
  current_function = $1;
}
| '*' IDENTIFIER '(' parameter_list ')' {
  if(current_function != "")
  {
	perror("A function cannot be defined inside another");
	exit(EXIT_FAILURE);
  }
  addr = 0;
  $$.element_type = bt; 
  $$.kind = 1; 
  $$.element_size = temp_param_stack.size();
  $$.code = new std::string("");
  vec.push_back($$.code); 
  //$$.function_parameters = $4;
  VariableStack.insert(std::pair<std::string, type_t>($2,$$)); 
  int i = 0;
  std::stringstream ss;
  std::stringstream ss2;
  for(map<std::string, type_t>::iterator it=temp_param_stack.begin() ; it!=temp_param_stack.end() ; ++it)
  {
	  ss << $2;
	  ss << " ";
	  ss << it->first;
	  VariableStack.insert(std::pair<std::string, type_t>(ss.str(),it->second));
	  ss2 << $2;
	  ss2 <<" ";
	  ss2 << i;
	  ParameterStack.insert(std::pair<std::string, type_t>(ss2.str(),it->second));

	  i++;
  }
  vec.clear();
  current_function = $2;
} 
| IDENTIFIER '(' ')' {
  if(current_function != "")
  {
	perror("A function cannot be defined inside another");
	exit(EXIT_FAILURE);
  }
  addr = 0;
  $$.element_type = bt;
  $$.kind = 1;
  $$.element_size = 0;
  std::stringstream s;
  s << ".globl	" << $1 << "\n";
  s << ".type	" << $1 << ", @function\n";
  s << $1 <<":\n";
  s << ".LFB" << nfunc << ":\n";
  s << ".cfi_startproc\n";
  s << "pushq	%rbp\n";
  s << ".cfi_def_cfa_offset 16\n";
  s << ".cfi_offset 6, -16\n";
  s << "movq	%rsp, %rbp\n";
  s << ".cfi_def_cfa_register 6\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  VariableStack.insert(std::pair<std::string, type_t>($1,$$)); 
  current_function = $1;
  }
| '*' IDENTIFIER '(' ')' {
  if(current_function != "")
  {
	perror("A function cannot be defined inside another");
	exit(EXIT_FAILURE);
  }
  addr = 0;
  $$.element_type = bt;
  $$.kind = 1;
  $$.element_size = 0;
  std::stringstream s;
  s << ".globl	" << $2 << "\n";
  s << ".type	" << $2 << ", @function\n";
  s << $2 << ":\n";
  s << ".LFB" << nfunc << ":\n";
  s << ".cfi_startproc\n";
  s << "pushq	%rbp\n";
  s << ".cfi_def_cfa_offset 16\n";
  s << ".cfi_offset 6, -16\n";
  s << "movq	%rsp, %rbp\n";
  s << ".cfi_def_cfa_register 6\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  VariableStack.insert(std::pair<std::string, type_t>($2,$$));
  current_function = $2;
  }
;

parameter_list
: parameter_declaration {$$ = $1;}
| parameter_list ',' parameter_declaration {
  $$ = $3;
  std::stringstream s;
  s << *$1.code;
  s << *$3.code;
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  }
;

parameter_declaration
: type_name declarator {$$ = $2;}
;

statement
: compound_statement {$$ = $1;}
| expression_statement {$$ = $1;}
| selection_statement {$$ = $1;}
| iteration_statement {$$ = $1;}
| jump_statement {$$ = $1;}
;

compound_statement
: '{' '}' {
  $$.code = new std::string("");vec.push_back($$.code);
 }
| '{' statement_list '}' {
  $$ = $2;
  } 
| '{' declaration_list statement_list '}' { $$ = $3;
   std::stringstream s;
   s << *$2.code;
   s << *$3.code;
   $$.code = new std::string(s.str());
   vec.push_back($$.code);
  } 
;

declaration_list
: declaration {$$ = $1;}
| declaration_list declaration {
  $$ = $2;
  std::stringstream s;
  s << *$1.code;
  s << *$2.code;
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
;

statement_list
: statement {$$ = $1;}
| statement_list statement {
  $$ = $2;
  std::stringstream s;
  s << *$1.code;
  s << *$2.code;
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
;

expression_statement
: ';' 
| expression ';' {
  $$ = $1;
  std::stringstream s;
  s << *$1.code;
  s << "popq %rax\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
;
selection_statement
: IF '(' expression ')' statement 
{	
  std::stringstream s;
  s << *$3.code;
  s << "popq %rax\n";
  s << "cmp %rax, $0\n";
  s << "je .L" << nlabel << "\n";
  s << *$5.code;
  s << ".L" << nlabel << ":\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  nlabel++;
}  
| IF '(' expression ')' statement ELSE statement 
{	
  std::stringstream s;
  s << *$3.code;
  s << "popq %rax\n";
  s << "cmpq $0, %rax\n";
  s << "je .L" << nlabel << "\n";
  s << *$5.code;
  s << "jmp .L" << (nlabel+1) << "\n";
  s << ".L" << nlabel << ":\n";
  s << *$7.code;
  s << ".L"<< (nlabel+1) <<":\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code); 
  nlabel += 2;
}  
;

iteration_statement
: WHILE '(' expression ')' statement 
{	
  std::stringstream s;
  s << ".L" << nlabel << ":\n";
  s << *$3.code;
  s << "popq %rax\n";
  s << "cmp %rax, $0\n";
  s << "je .L" << nlabel+1 << "\n";
  s << *$5.code;
  s << "jmp .L" << nlabel << "\n";
  s << ".L" << nlabel+1 << ":\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  nlabel += 2;
}  
| FOR '(' expression_statement expression_statement expression ')' statement 
{	
  std::stringstream s;
  s << *$3.code;
  s << ".L" << nlabel << ":\n";
  s << *$4.code;
  s << "popq %rax\n";
  s << "cmp %rax, $0\n";
  s << "je .L" << nlabel+1 << "\n";
  s << *$7.code;
  s << *$5.code;
  s << "jmp .L" << nlabel << "\n";
  s << ".L" << nlabel+1 << ":\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  nlabel += 2;
}  
| DO  statement  WHILE '(' expression ')' ';' 
{	
  std::stringstream s;
  s << ".L" << nlabel << ":\n";
  s << *$2.code;
  s << *$5.code;
  s << "popq %rax\n";
  s << "cmp %rax, $0\n";
  s << "je .L" << nlabel+1 << "\n";
  s << "jmp .L" << nlabel << "\n";
  s << ".L" << nlabel+1 << ":\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  nlabel += 2;
}  
;

jump_statement
: RETURN ';' {
  $$.code = new std::string("movq $1, -8(%rbp)\n");
  vec.push_back($$.code);
 }
| RETURN expression ';' {
  std::stringstream s;
  s << "popq %rax\nmovq %rax, " << -$2.addre << "(%rbp)\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
;

program
: external_declaration {}
| program external_declaration {}
;

external_declaration
: function_definition  {}
| declaration {}
;

function_definition
: type_name declarator compound_statement {
  std::stringstream s;
  s<< *$2.code;
  s << *$3.code;
  s << ".cfi_def_cfa 7, 8\nret\n.cfi_endproc\n.LFE" << nfunc << ":\n";
  s << ".size	";
  s << current_function;
  s << ", .-" << current_function << "\n"; 
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  printCode($$.code);
  current_function = "";
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

void printCode (std::string* code) {
  std::cout << *code;
  for (std::string* i : vec)
    {
      delete(i);
    }
  vec.clear();
}
void print_printint(){
  std::stringstream s;
  s << ".section	.rodata\n";
  s << ".LC0:\n";
  s << ".string	\"%d\\n\"\n";
  s << ".text\n";
  s << ".globl	printint\n";
  s << ".type	printint, @function\n";
  s << "printint:\n";
  s << ".LFB0:\n";
  s << ".cfi_startproc\n";
  s << "pushq	%rbp\n";
  s << ".cfi_def_cfa_offset 16\n";
  s << ".cfi_offset 6, -16\n";
  s << "movq	%rsp, %rbp\n";
  s << ".cfi_def_cfa_register 6\n";
  s << "subq	$16, %rsp\n";
  s << "movq	%rdi, -8(%rbp)\n";
  s << "movq	-8(%rbp), %rax\n";
  s << "movq	%rax, %rsi\n";
  s << "movq	$.LC0, %rdi\n";
  s << "movq	$0, %rax\n";
  s << "call	printf\n";
  s << "leave\n";
  s << ".cfi_def_cfa 7, 8\n";
  s << "ret\n";
  s << ".cfi_endproc\n";
  s << ".LFE0:\n";
  s << ".size	printint, .-printint\n";
  printf("%s", s.str().c_str());
}

void print_printfloat(){
  std::stringstream s;
  s << ".section	.rodata\n";
  s << ".LC1:\n";
  s << ".string	\"%f\\n\"\n";
  s << ".text\n";
  s << ".globl	printfloat\n";
  s << ".type	printfloat, @function\n";
  s << "printfloat:\n";
  s << ".LFB1:\n";
  s << ".cfi_startproc\n";
  s << "pushq	%rbp\n";
  s << ".cfi_def_cfa_offset 16\n";
  s << ".cfi_offset 6, -16\n";
  s << "movq	%rsp, %rbp\n";
  s << ".cfi_def_cfa_register 6\n";
  s << "subq	$16, %rsp\n";
  s << "movss	%xmm0, -8(%rbp)\n";
  s << "movss	-8(%rbp), %xmm0\n";
  s << "cvtps2pd	%xmm0, %xmm0\n";
  s << "movq	$.LC1, %rdi\n";
  s << "movq	$1, %rax\n";
  s << "call	printf\n";
  s << "leave\n";
  s << ".cfi_def_cfa 7, 8\n";
  s << "ret\n";
  s << ".cfi_endproc\n";
  s << ".LFE1:\n";
  s << ".size	printfloat, .-printfloat\n";
  printf("%s", s.str().c_str());
}


int main (int argc, char *argv[]) {
  FILE *input = NULL;
  if (argc==2) {
    printf(".file	\"%s\"\n",argv[1]);
    print_printint();
    print_printfloat();
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
