%{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
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
  int nfunc = 0;
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
%token IF ELSE WHILE RETURN FOR DO PRAGMA
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
%type <t> pragma_statement
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
  std::stringstream s;
  s << "pushq -"<< local_identifier.addre <<"(%rbp)\n";
  $$.code = new std::string(s.str());
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
  char floatbuffer[100];
  sprintf(floatbuffer, "%d", $1);
  
  std::stringstream s;
  s << "pushq $" << floatbuffer << "\n";
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
  std::stringstream s;
  s << *$3.code;
  for (int i = $$.element_size - 1; i>=0; --i)
  {
	std::stringstream ss;
	ss << $1 << " "<< i;
	if( ParameterStack[ss.str()].element_type != temp_appel_param_stack[i].element_type){
	
		
		//perror("type not valid (argument)");
		//exit(EXIT_FAILURE);
	}
	switch(i){   // mise en mémoire des parametres
		case 0:
		s <<"popq %rax\nmovq	%rax, %rdi\n";
		break;		
		case 1:
		s <<"popq %rax\nmovq	%rax, %rsi\n";
		break;	
		case 2:
		s <<"popq %rax\nmovq	%rax, %rdx\n";
		break;		
		case 3:
		s <<"popq %rax\nmovq	%rax, %rcx\n";			
		break;			
		case 4:
		s <<"popq %rax\nmovq	%rax, %r8\n";
		break;		
		case 5:
		s <<"popq %rax\nmovq	%rax, %r9\n";		
		break;	
		case 6:   //incorect
		s <<"popq %rax\nmovq	%rax, (%rsp)\n";		
		break;		
		default:
		int local_addre = 8*(i-5);
		s <<"popq %rax\nmovq	%rax, "<< local_addre <<"(%rsp)\n";
		break;
	}	  
  }	

  s << "call " << $1 <<"\n";
	s << "pushq %rax\n";
  $$.code = new std::string(s.str());
  temp_appel_param_stack.clear();
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
	s << "movq " << -local_identifier.addre << "(%rbp), %rax\n";
    s << "movq %rax, %xmm0\n";
	s << "movq " << "$1" << ", %rbx\n";
	s << "movq %rbx, %xmm1\n";
	s << "addss %xmm1,%xmm0\n";
	s << "movq %xmm0,%rax\n";
	s << "pushq %rax\n";
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
    s << "movq " << -local_identifier.addre << "(%rbp), %rax\n";
    s << "movq %rax, %xmm0\n";
	s << "movq " << "$1" << ", %rbx\n";
	s << "movq %rbx, %xmm1\n";
	s << "subss %xmm1,%xmm0\n";
	s << "movq %xmm0,%rax\n";
	s << "pushq %rax\n";
  }
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
| IDENTIFIER '[' expression ']' {
  type_t local_identifier = VariableStack[current_function + " "+$1];
  $$ = local_identifier; 
	  if(local_identifier.kind == 0)
	  {
		  if(local_identifier.element_type == INT_T) {
			std::stringstream s;
			s << *$3.code;
			s << "popq %rax\nmovq -";
			s << local_identifier.addre;
			s << "(%rbp, %rax, 8), %rax\npushq %rax\n"; 
			$$.code = new std::string(s.str());
			vec.push_back($$.code);
			}
	}
	else if(local_identifier.kind == -1)
	{
		if(local_identifier.element_type == INTSTAR_T) { // a revoir peutr-etre
			std::stringstream s;
			s << *$3.code;
			s << "popq %rax\nimul $8 %rax";
			s << "movq -"<< local_identifier.addre << "(%rbp), %rbx\n";
			s << "addq %rax, %rbx\n "; 
			s << "pushq (%rbx)\n";
			$$.code = new std::string(s.str());
			vec.push_back($$.code);
		
		}
	
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
    s << "popq %rax";
    s << "movq %rax, %xmm0\n";
	s << "negss %xmm0\n";
	s << "movq %xmm0,%rax\n";
	s << "pushq %rax\n";
  }
  else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
	}
  }
| '!' unary_expression {
  $$ = $2;
  if ($2.element_type == INT_T)
    {   
      std::stringstream s;
      s << *$2.code;
      s << "popq %rax\n";
      s << "movq $0, %rbx\n";
      s << "cmpq %rbx, %rax\n";
      s << "jne .L" << nlabel << "\n";
      s << "pushq $1\n";
      s << "jmp .L" << (nlabel+1) << "\n";
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
    s << "popq %rax";
    s << "movq %rax, %xmm0\n";
    s << "movq " << "$1" << ", %rbx\n";
    s << "movq %rbx, %xmm1\n";
    s << "cmpeqss %xmm0, %xmm1\n";
    s << "jne .L" << nlabel << "\n";
    s << "pushq $1\n";
    s << "jmp .L" << (nlabel+1) << "\n";
    s << ".L" << nlabel << ":\n";
    s << "pushq $0\n";
    s << ".L"<< (nlabel+1) <<":\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
    nlabel += 2;
  }
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "movq %rax, %xmm0\n";
      s << "popq %rbx\n";
	  s << "movq %rbx, %xmm1\n";
	  s << "mulss %xmm1,%xmm0\n";
	  s << "movq %xmm0,%rax\n";
	  s << "pushq %rax\n";
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
      s << "movq %rax, %xmm0\n";
      s << "popq %rbx\n";
	  s << "movq %rbx, %xmm1\n";
	  s << "mulss %xmm1,%xmm0\n";
	  s << "movq %xmm0,%rax\n";
	  s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
      std::stringstream s;
      s << *$1.code;
      s << *$3.code;
      s << "popq %rax\n";
      s << "movq %rax, %xmm0\n";
      s << "popq %rbx\n";
	  s << "movq %rbx, %xmm1\n";
	  s << "mulss %xmm1,%xmm0\n";
	  s << "movq %xmm0,%rax\n";
	  s << "pushq %rax\n";
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
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "addss %xmm1,%xmm0\n";
	  s << "movd %xmm0,%rax\n";
	  s << "pushq %rax\n";
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
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "addss %xmm1,%xmm0\n";
	  s << "movd %xmm0,%rax\n";
	  s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
      $$.element_type = FLOAT_T;
     std::stringstream s;
      s << *$1.code;
      s << *$3.code;
	  s << "popq %rax\n";
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "addss %xmm1,%xmm0\n";
	  s << "movd %xmm0,%rax\n";
	  s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
    else{
		perror("irregular operation");
		exit(EXIT_FAILURE);
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
      s << "subq %rax, %rbx\n";
      s << "pushq %rbx\n";
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
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "subss %xmm0,%xmm1\n";
	  s << "movd %xmm1,%rax\n";
	  s << "pushq %rax\n";
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
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "subss %xmm0,%xmm1\n";
	  s << "movd %xmm1,%rax\n";
	  s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
  else if (($1.element_type == FLOAT_T)&&($3.element_type == FLOAT_T))
    {
       $$.element_type = FLOAT_T;
     std::stringstream s;
      s << *$1.code;
      s << *$3.code;
	  s << "popq %rax\n";
	  s << "movd %rax, %xmm0\n";
	  s << "popq %rbx\n";
	  s << "movd %rbx, %xmm1\n";
	  s << "subss %xmm0,%xmm1\n";
	  s << "movd %xmm1,%rax\n";
	  s << "pushq %rax\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
    }
      else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "jl .L" << nlabel << "\n";
      s << "pushq $0\n";
      s << "jmp .L" << (nlabel + 1) << "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $1\n";
      s << ".L" << (nlabel+1) << ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+= 2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "jg .L" << nlabel << "\n";
      s << "pushq $0\n";
      s << "jmp .L" << (nlabel + 1) << "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $1\n";
      s << ".L" << (nlabel+1) << ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+=2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "jle .L" << nlabel << "\n";
      s << "pushq $0\n";
      s << "jmp .L" << nlabel + 1<< "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $1\n";
      s << ".L" << nlabel +1<< ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+=2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "jle .L" << nlabel << "\n";
      s << "pushq $1\n";
      s << "jmp .L" << nlabel + 1<< "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $0\n";
      s << ".L" << nlabel +1<< ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+=2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "je .L" << nlabel << "\n";
      s << "pushq $0\n";
      s << "jmp .L" << nlabel + 1<< "\n";
      s << ".L" << nlabel << ":\n";
      s << "pushq $1\n";
      s << ".L" << nlabel + 1<< ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+=2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
      s << "cmpq %rax, %rbx\n";
      s << "jne .L" << nlabel << "\n";
      s << "pushq $0\n";
      s << "jmp .L" << nlabel + 1 << "\n";
	  s << ".L" << nlabel << ":\n";
      s << "pushq $1\n";
      s << ".L" << nlabel + 1<< ":\n";
      $$.code = new std::string(s.str());
      vec.push_back($$.code);
      nlabel+=2;
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
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
  else if ((local_identifier.element_type == FLOAT_T)&&($3.element_type == FLOAT_T)){
	
    std::stringstream s;
    s << *$3.code;
    s << "popq %rax\nmovq %rax, " << -local_identifier.addre << "(%rbp)\npushq %rax\n";
    $$.code = new std::string(s.str());
    vec.push_back($$.code);
  }
  else if(local_identifier.element_type == INTSTAR_T || local_identifier.element_type == FLOATSTAR_T) 
  {
  
	 if($3.element_type == local_identifier.element_type && ($3.kind == -1 || $3.kind == 1)) // egalite entre pointeurs
	 {
	    std::stringstream s;
		s << *$3.code;
		s << "popq %rax\n";
		s << "movq %rax, " << -local_identifier.addre << "(%rbp)\n";
		s << "pushq %rax\n";
		$$.code = new std::string(s.str());
		vec.push_back($$.code);
	 }
	 else if(($3.kind == 0) && ($3.element_type == local_identifier.element_type - 1)) //pointeur egal vecteur
	 {
	  std::stringstream s;
	  s << *$3.code;
	  s << "leaq -" << local_identifier.addre << "(%rbp), %rax\n";
	  s << "movq %rax, -" <<  $3.addre << "(%rbp)\npushq -" << $3.addre << "(%rbp)\n";
	  $$.code = new std::string(s.str());
	  vec.push_back($$.code);
	 }
	 else
	 {
		perror("invalid operation");
		exit(EXIT_FAILURE);
	 
	 }
  }
    else{
		perror("Irregular Operation\n");
		exit(EXIT_FAILURE);
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
	  $$.code = new std::string("pushq %rax\n");
	  vec.push_back($$.code);
	  VariableStack.insert ( std::pair<std::string, type_t>(current_function +" "+$1,$$) );
		}
	else {  //parametre de fonction
  
  	  $$.element_type = bt;
	  $$.kind = -1 ;
	  $$.code = new std::string("pushq %rax\n");
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
		  $$.code = new std::string("pushq %rax\n");
		  vec.push_back($$.code);
		  VariableStack.insert ( std::pair<std::string, type_t>(current_function +" "+$2,$$) );
		}
	}
	else {  //parametre de fonction
  
  		$$.addre = addr;
  		$$.element_type = (type)(bt+1); 
		$$.kind = -1;
  		$$.code = new std::string("pushq %rax\n");
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
	  $$.code = new std::string("pushq %rax\n"); 
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

  //$$.function_parameters = $3; 
  VariableStack.insert(std::pair<std::string, type_t>($1, $$)); 
  int i = 0;

  for(map<std::string, type_t>::iterator it=temp_param_stack.begin() ; it!=temp_param_stack.end() ; ++it)
  {
      std::stringstream ss;
      std::stringstream ss2;
  	  ss << $1;
	  ss << " ";
	  ss << it->first;
	  VariableStack.insert(std::pair<std::string, type_t>(ss.str(),it->second)); //on le stock comme une variable normale pour y acceder dans la fonction concernee
	  ss2 << $1;
	  ss2 <<" ";
	  ss2 << i;
	  ParameterStack.insert(std::pair<std::string, type_t>(ss2.str(),it->second)); //on duplique pour pouvoir rechercher les parametres facilement hors de la fonction
	  s << "pushq %rax\n";
	switch(i){
		case 0:
		s <<"movq	%rdi, -8(%rbp)\n";
		break;		
		case 1:
		s <<"movq	%rsi, -16(%rbp)\n";	
		break;
		case 2:
		s <<"movq	%rdx, -24(%rbp)\n";
		break;		
		case 3:
		s <<"movq	%rcx, -32(%rbp)\n";			
		break;			
		case 4:
		s <<"movq	%r8, -40(%rbp)\n";
		break;		
		case 5:
		s <<"movq	%r9, -48(%rbp)\n";		
		break;		
		default:

		break;
	}
	addr+=8;
	  VariableStack[ss.str()].addre = 8*(i+1);
	  i++;
  } 
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
  temp_param_stack.clear();
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
   std::stringstream s;
  s << ".globl	" << $2 << "\n";
  s << ".type	" << $2 << ", @function\n";
  s << $2 <<":\n";
  s << ".LFB" << nfunc << ":\n";
  s << ".cfi_startproc\n";
  s << "pushq	%rbp\n";
  s << ".cfi_def_cfa_offset 16\n";
  s << ".cfi_offset 6, -16\n";
  s << "movq	%rsp, %rbp\n";
  s << ".cfi_def_cfa_register 6\n";

  VariableStack.insert(std::pair<std::string, type_t>($2,$$)); 
  int i = 0;
  for(map<std::string, type_t>::iterator it=temp_param_stack.begin() ; it!=temp_param_stack.end() ; ++it)
  {
      std::stringstream ss;
      std::stringstream ss2;
	  ss << $2;
	  ss << " ";
	  ss << it->first;
	  VariableStack.insert(std::pair<std::string, type_t>(ss.str(),it->second));
	  ss2 << $2;
	  ss2 <<" ";
	  ss2 << i;
	  ParameterStack.insert(std::pair<std::string, type_t>(ss2.str(),it->second));
    s << "pushq %rax\n";
	switch(i){
		case 0:
		s <<"movq	%rdi, -8(%rbp)\n";
		break;		
		case 1:
		s <<"movq	%rsi, -16(%rbp)\n";	
		break;
		case 2:
		s <<"movq	%rdx, -24(%rbp)\n";
		break;		
		case 3:
		s <<"movq	%rcx, -32(%rbp)\n";			
		break;			
		case 4:
		s <<"movq	%r8, -40(%rbp)\n";
		break;		
		case 5:
		s <<"movq	%r9, -48(%rbp)\n";		
		break;		
		default:

		break;
	}
	  addr+=8;
	  VariableStack[ss.str()].addre = 8*(i+1);

	  i++;
  }
  $$.code = new std::string(s.str());
  vec.push_back($$.code); 
  temp_param_stack.clear();
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
| pragma_statement {$$ = $1;}
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
: ';' {
 $$.code = new std::string("");
 vec.push_back($$.code);
}
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
  s << "movq $0, %rbx\n";
  s << "cmpq %rax, %rbx\n";
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
  s << "movq $0, %rbx\n";
  s << "cmpq %rbx, %rax\n";
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
  s << "movq $0, %rbx\n";
  s << "cmpq %rax, %rbx\n";
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
  s << "pushq %rax\n"; //push du ;
  s << ".L" << nlabel << ":\n";
  s << *$4.code;
  s << "pushq %rax\n"; //push du ;
  s << "popq %rax\n";
  s << "movq $0, %rbx\n";
  s << "cmpq %rax, %rbx\n";
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
  s << "movq $0, %rbx\n";
  s << "cmpq %rax, %rbx\n";
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
  $$.code = new std::string("");
  vec.push_back($$.code);
 }
| RETURN expression ';' { 
  std::stringstream s;
  s << *$2.code;
  s << "popq %rax\n";
  $$.code = new std::string(s.str());
  vec.push_back($$.code);
 }
;

program
: external_declaration {}
| program external_declaration {}
;

external_declaration
: function_definition  { $$ = $1;}
| declaration { current_function = ""; $$ = $1;}
;

function_definition
: type_name declarator compound_statement {
  std::stringstream s;
  s<< *$2.code;
  s << *$3.code;
	s << "leave\n";
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
pragma_statement
: PRAGMA FOR '(' IDENTIFIER '=' ICONSTANT ';' IDENTIFIER '<' ICONSTANT ';' IDENTIFIER '=' IDENTIFIER '+' ICONSTANT ')' statement {

	if ( !($4 == $8 && $4 == $12 && $4 == $14))
	{
		perror("indentifer must be UNIQUE");
		exit(EXIT_FAILURE);
	}
	if($16 != 1)
	{
		perror("increment must be of size 1");
		exit(EXIT_FAILURE);
	}
	

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
  type_t int_param;
  int_param.element_type = INT_T;
  int_param.kind = -1;
  
  type_t printint;
  printint.element_type = VOID_T;
  printint.element_size = 1;
  printint.kind = 1;
  std::stringstream s1;
  std::stringstream s2;
  s1 << "printint" << " " << "x";
  s2 << "printint";
  VariableStack.insert ( std::pair<std::string, type_t>(s1.str(),int_param) );
  VariableStack.insert(std::pair<std::string, type_t>(s2.str(),printint)); 
  ParameterStack.insert(std::pair<std::string, type_t>(s1.str(),int_param));
  
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
  
  type_t int_param;
  int_param.element_type = FLOAT_T;
  int_param.kind = -1;
  
  type_t printint;
  printint.element_type = VOID_T;
  printint.element_size = 1;
  printint.kind = 1;
  std::stringstream s1;
  std::stringstream s2;
  s1 << "printfloat" << " " << "x";
  s2 << "printfloat";
  VariableStack.insert ( std::pair<std::string, type_t>(s1.str(),int_param) );
  VariableStack.insert(std::pair<std::string, type_t>(s2.str(),printint)); 
  ParameterStack.insert(std::pair<std::string, type_t>(s1.str(),int_param));

}

void print_malloc_int(){
std::stringstream s;
s << "malloc_int:\n";
s << ".LFB2:\n";
s << ".cfi_startproc\n";
s << "pushq %rbp\n";
s << ".cfi_def_cfa_offset 16\n";
s << ".cfi_offset 6, -16\n";
s << "movq %rsp, %rbp\n";
s << ".cfi_def_cfa_register 6\n";
s << "subq $32, %rsp\n";
s << "movq %rdi, -20(%rbp)\n";
s << "movq $4, %rdi\n";
s << "call malloc\n";
s << "movq %rax, -8(%rbp)\n";
s << "movq -8(%rbp), %rax\n";
s << "movq -20(%rbp), %rdx\n";
s << "movq %rdx, (%rax)\n";
s << "movq -8(%rbp), %rax\n";
s << "leave\n";
s << ".cfi_def_cfa 7, 8\n";
s << "ret\n";
s << ".cfi_endproc\n";
s << ".LFE2:\n";
s << ".size malloc_int, .-malloc_int\n";
printf("%s", s.str().c_str());

  type_t malloc_param;
  malloc_param.element_type = INT_T;
  malloc_param.kind = -1;
  
  type_t malloc_int;
  malloc_int.element_type = INTSTAR_T;
  malloc_int.element_size = 1;
  malloc_int.kind = 1;
  std::stringstream s1;
  std::stringstream s2;
  s1 << "malloc_int" << " " << "x";
  s2 << "malloc_int";
  VariableStack.insert ( std::pair<std::string, type_t>(s1.str(),malloc_param) );
  VariableStack.insert(std::pair<std::string, type_t>(s2.str(),malloc_int)); 
  ParameterStack.insert(std::pair<std::string, type_t>(s1.str(),malloc_param));
} 


int main (int argc, char *argv[]) {
  FILE *input = NULL;
  if (argc==2) {
    printf(".file	\"%s\"\n",argv[1]);
    print_printint();nfunc++;
    print_printfloat();nfunc++;
    print_malloc_int();nfunc++;
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
