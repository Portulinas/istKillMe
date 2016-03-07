#include "final.h"

void listSorted(User ArrayUsers, int u) {
	/*Lista ordenadamente todas as mensagens do utilizador u*/
	int i, NUM_MENSAGENS=0;
	link pointers;
	link first;

	first = ArrayUsers[u].head_queue;
	
	if(first == NULL){
		printf("NULL\n");	
	}else{
		/*Contagem do numero de mensagens*/
		while(first != NULL){
			first = first -> next;
			NUM_MENSAGENS++;
		}
		/*Copia da lista para um array auxiliar*/
		pointers = malloc(NUM_MENSAGENS * sizeof(struct node));
		first = ArrayUsers[u].head_queue;
		for(i=0;i<NUM_MENSAGENS;i++, first = first->next){
			pointers[i].item = first -> item;
			pointers[i].next = first -> next;
			
		}
	/*Ordenacao e escrita do resultado*/
	qsort(pointers,NUM_MENSAGENS,sizeof(struct node),compare);	
	for(i=0;i<NUM_MENSAGENS;i++)
		printMessage(pointers[i].item->e, pointers[i].item->r, pointers[i].item->text);
	free(pointers);
	}

}
