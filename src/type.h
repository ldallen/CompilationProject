#ifndef TYPE_H
#define TYPE_H

enum type{INT_T, INTSTAR_T, FLOAT_T, FLOATSTART_T, VOID_T};

typedef struct type_t{
	int kind; // -1 = single , 0 = array, 1 = function
	enum type element_type;
	int element_size;
	struct type_t* function_parameters;   
	 
} type_t;
#endif