#include "final.h"


void kill(User ArrayUsers,int u){
	/*Apaga todas as mensagens da fila do utilizador u*/
	link pointer;
	pointer = ArrayUsers[u].head_queue;
	
	while(pointer != NULL){
		deletaMensagem(ArrayUsers, u);
		pointer = ArrayUsers[u].head_queue;
	}
}
