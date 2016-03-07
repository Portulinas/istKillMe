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

void kill(User ArrayUsers,int u){
	link pointer;
	pointer = ArrayUsers[u].head_queue;
	
	while(pointer != NULL){
		deletaMensagem(ArrayUsers, u);
		pointer = ArrayUsers[u].head_queue;
	}
}

/*	qsort(pointers,NUM_MENSAGENS,sizeof(struct node),compare);	*/
int compare(const void *p1, const void *p2)
{
	int resultado;
	Item ip1 = *(Item *)p1;
	Item ip2 = *(Item *)p2;
	resultado  = strcmp(ip1->text,ip2->text);
	if(resultado) 				
		return resultado;
	return (ip1->e - ip2->e);
}


void listSorted(User ArrayUsers) {
	int i,u, NUM_MENSAGENS=0;
	link pointers;
	link first;
	
	scanf("%d", &u);
	first = ArrayUsers[u].head_queue;
	
	if(first == NULL){
		printf("NULL\n");	
	}else{
		while(first != NULL){
			first = first -> next;
			NUM_MENSAGENS++;
		}
		pointers = malloc(NUM_MENSAGENS * sizeof(struct node));
		
		first = ArrayUsers[u].head_queue;
		for(i=0;i<NUM_MENSAGENS;i++, first = first->next){
			pointers[i].item = first -> item;
			pointers[i].next = first -> next;
		}
	}

	qsort(pointers,NUM_MENSAGENS,sizeof(struct node),compare);	

	
	for(i=0;i<NUM_MENSAGENS;i++)
		printMessage(pointers[i].item->e, pointers[i].item->r, pointers[i].item->text);
	free(pointers);
}

/***************MAIN***************/

int main() {
	int N_USERS,u;
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

