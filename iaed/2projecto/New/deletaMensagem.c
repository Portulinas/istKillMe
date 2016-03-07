#include "final.h"

void deletaMensagem(User ArrayUsers, int u){
	/*Apaga a primeira mensagem do utilizador u*/
	link aux;	
	free(ArrayUsers[u].head_queue -> item -> text);
	free(ArrayUsers[u].head_queue -> item);
	aux = ArrayUsers[u].head_queue -> next;
	free(ArrayUsers[u].head_queue);
	ArrayUsers[u].head_queue = aux;
}
