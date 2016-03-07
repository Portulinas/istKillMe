#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRCTRS 501
#define MAXINPUT 11

/*************ESTRUTURAS*************/

typedef struct mensagem {
	int e;
	int r;
	char* text;
}*Item;

typedef struct node {
	Item item;
	struct node *next;
}*link;


typedef struct user {
	link head_queue;
	link tail_queue;	
}*User;



/**************FUNCOES**************/

Item criaMensagem(int sender, int receiver, char *texto){
	Item msg;
	msg = malloc(sizeof(struct mensagem));
	
	msg -> e = sender;
	msg -> r = receiver;
	msg -> text = (char*) malloc( (strlen(texto)+1) * sizeof(char) );
	strcpy(msg->text,texto);

	return msg;
}

link criaNode(Item msg){
	link new_node;
	new_node = malloc(sizeof(struct node));
	
	new_node -> item = msg;
	new_node -> next = NULL;
	
	return new_node;
}

void printMessage(int e, int r, char *text){
	printf("%d %d %s",r,e,text);
}

int isEmpty(User ArrayUsers, int u) {
	return (ArrayUsers[u].head_queue == NULL);
}



void deletaMensagem(User ArrayUsers, int u){
	link aux;	
	
	free(ArrayUsers[u].head_queue -> item -> text);
	free(ArrayUsers[u].head_queue -> item);
	
	aux = ArrayUsers[u].head_queue -> next;
	free(ArrayUsers[u].head_queue);
	
	ArrayUsers[u].head_queue = aux;
}



/*************COMANDOS*************/

void send(User ArrayUsers) {
	char input[CRCTRS];
	int sender, receiver;
	link last;
	link first;
	
	scanf("%d%d ", &sender, &receiver); 		/*guarda o 'e' e o 'r'*/
	fgets(input, CRCTRS, stdin); 			 	/*guarda o texto da mensagem em input*/

	
	

	if (isEmpty(ArrayUsers, receiver)) {
		first = criaNode(criaMensagem(sender,receiver,input));
		ArrayUsers[receiver].head_queue = first;
		ArrayUsers[receiver].tail_queue = first;
		
	}else{
		last = criaNode(criaMensagem(sender,receiver,input));
		ArrayUsers[receiver].tail_queue -> next = last;		
		ArrayUsers[receiver].tail_queue = last;
		}
}



void process(User ArrayUsers){
	int u;
	scanf("%d",&u);
	
	if(!(isEmpty(ArrayUsers, u))){
		printMessage(ArrayUsers[u].head_queue->item->e ,ArrayUsers[u].head_queue->item->r , ArrayUsers[u].head_queue->item->text);
		deletaMensagem(ArrayUsers,u);
	}else{
		printf("NULL\n");
	}
}


void list(User ArrayUsers){
	int u;
	link pointer;
	
	scanf("%d",&u);
	
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

void kill(User ArrayUsers, int u){
	link pointer;
	pointer = ArrayUsers[u].head_queue;
	
	while(pointer != NULL){
		deletaMensagem(ArrayUsers, u);
		pointer = ArrayUsers[u].head_queue;
	}
}

int compare(const void *p1, const void *p2) {
	int resultado;
	
	resultado  = strcmp(((struct node *)p1)->item->text,((struct node *)p2)->item->text);
	if (resultado != 0) 
		return resultado;
	else
	    return ((struct node *)p1)->item->e-((struct node *)p2)->item->e;

}

void listSorted(User ArrayUsers) {
	int u, NUM_MENSAGENS = 0;
	User Copia;
	link first;
	link aux;
	
	Copia  = calloc(1,sizeof(struct user));
	
	scanf("%d", &u);
	first = ArrayUsers[u].head_queue;
	
	if(first==NULL){
		printf("NULL\n");	
	}else{
		aux = criaNode(criaMensagem(first->item->e,first->item->r,first->item->text));
		Copia->head_queue = aux;
		Copia->tail_queue = aux;	
		first = first -> next;	
		while(first!=NULL){
			aux = criaNode(criaMensagem(first->item->e,first->item->r,first->item->text));
			Copia->tail_queue ->next = aux;
			Copia->tail_queue = aux;
			first = first->next;
			NUM_MENSAGENS++;
		}
			
	}	

		
	if(Copia->head_queue==NULL){
		printf("NULL\n");
	}else{
		qsort(Copia,NUM_MENSAGENS,sizeof(struct node),compare);
		aux = Copia->head_queue;
		while (aux != NULL){
			printMessage(aux->item->e , aux->item->r , aux->item->text);
			aux = aux -> next;
		}
	}
	
	first = Copia->head_queue;
		
	
	while(first!=NULL){
		free(Copia -> head_queue -> item -> text);
		free(Copia -> head_queue -> item);

		aux = Copia->head_queue -> next;

		free(Copia->head_queue);

		Copia->head_queue = aux;	
			
		first = Copia -> head_queue;
	}
	free(Copia);

}

/***************MAIN***************/

int main() {
	int u,N_USERS;
	char input[MAXINPUT];
	User ArrayUsers;
	scanf("%d", &N_USERS);
	ArrayUsers  = calloc(N_USERS, sizeof(struct user));
		

	while (1) {
		scanf("%s",input);
		if (strcmp(input,"send") == 0) 
			send(ArrayUsers);
			
		if (strcmp(input,"process") == 0)
			process(ArrayUsers);
			
		if (strcmp(input,"list") == 0)
			list(ArrayUsers);

		if (strcmp(input,"kill") == 0){ 
			scanf("%d",&u);
			kill(ArrayUsers,u);
		}
		if (strcmp(input,"listsorted") == 0) 
			listSorted(ArrayUsers);

		
		if (strcmp(input,"quit") == 0) {
			for(u=0;u<N_USERS;u++)
				kill(ArrayUsers,u);
			free(ArrayUsers);
			return EXIT_SUCCESS;
		} 
	
	}
	free(ArrayUsers);
	return EXIT_FAILURE;
}

