#ifndef POTATOTOE_H
#define POTATOTOE_H

typedef struct type
{
	enum {FUNCTION,INT,INTSTAR,INTVECT,FLOAT,FLOATSTAR,VOID} type; //type = 0 -> function, = 4 -> float, = 5 -> float*, = 1 -> int, = 2 -> int*, = 3 -> int[], = 6 -> void  
	unsigned int size; // nb de parametres de la fonction si type = 0, taille du tableau si type = 3, 0 sinon 
	struct type_t* params; //parametres sous forme de "type_t" le premier est le type de retour de la fonction
} type_t;

#endif 
