#include "final.h"

link criaNode(Item msg){
	/*Cria um novo node com a mensagem msg*/
	link new_node;
	new_node = malloc(sizeof(struct node));
	new_node -> item = msg;
	new_node -> next = NULL;
	return new_node;
}
