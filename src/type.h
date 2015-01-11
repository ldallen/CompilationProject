#ifndef TYPE_H
#define TYPE_H
#include <iostream>


enum type{INT_T, INTSTAR_T, FLOAT_T, FLOATSTAR_T, VOID_T};

typedef struct type_t{
  int kind; // -1 = single , 0 = array, 1 = function
  enum type element_type;
  int element_size; // size for an array or number of parameters for a function
  struct type_t* function_parameters;   
  int addre ;
  std::string* code;
} type_t;
#endif
