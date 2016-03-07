#include "final.h"

void list(User ArrayUsers, int u){
	/*Lista todas as mensagens do utilizador u*/
	
	link pointer;	

	if(isEmpty(ArrayUsers, u)){
		printf("NULL\n");
	}else{
		pointer = ArrayUsers[u].head_queue;
		while (pointer != NULL){
			printMessage(pointer->item->e , pointer->item->r , pointer->item->text);
			pointer = pointer -> next;
		}
	}
}
