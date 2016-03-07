#include "final.h"

int compare(const void *p1, const void *p2) {
	/*Compara dois itens consecutivos; usada pela funcao qsort()*/
	int resultado;
	Item ip1 = *(Item *)p1;
	Item ip2 = *(Item *)p2;
	resultado  = strcmp(ip1->text,ip2->text);
	if(resultado) 				
		return resultado;
	return (ip1->e - ip2->e);
}
