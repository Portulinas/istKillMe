#include "final.h"


int isEmpty(User ArrayUsers, int u) {
	/*Verifica se a fila do utilizador u esta vazia*/
	return (ArrayUsers[u].head_queue == NULL);
}
