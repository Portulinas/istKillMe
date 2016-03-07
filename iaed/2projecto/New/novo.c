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
	msg -> text = (char*) malloc((strlen(texto)+1*sizeof(char)));
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



void deletaMensagem(User ArrayUsers, int u){
	link aux;	
	
	free(ArrayUsers[u].head_queue -> item -> text);
	free(ArrayUsers[u].head_queue -> item);
	
	aux = ArrayUsers[u].head_queue -> next;
	free(ArrayUsers[u].head_queue);
	
	ArrayUsers[u].head_queue = aux;
}

void printMenu() {
	printf("\t******** COMANDOS ********\n\n");
	printf("send e r info \t regista a mensagem info enviada pelo emissor e\n\t\t\t para o utilizador r.\n\t\t Limite 500 caracteres (incluindo espacos).\n");
	printf("process u \t imprime a proxima mensagem para utilizador u.\n");
	printf("list u \t\t lista as mensagens em espera para o utilizador u \n\t\t\tpor ordem de chegada.\n");
	printf("listsorted u \t list por ordem alfabetica.\n");
	printf("kill u \t\t apaga todas as mensagens em espera do utilizador u.\n");
	printf("quit \t\t apaga todas as mensagens em espera e sai do programa.\n\n");
}

/*************COMANDOS*************/

void send(User ArrayUsers) {
	char input[CRCTRS];
	int sender, receiver;
	link last;
	link first;
	link pos_node;
	
	scanf("%d%d ", &sender, &receiver); 		/*guarda o 'e' e o 'r'*/
	fgets(input, CRCTRS, stdin); 			 	/*guarda o texto da mensagem em input*/

	
	pos_node = ArrayUsers[receiver].head_queue;
	

	if (pos_node == NULL) {
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
	
	if(ArrayUsers[u].head_queue != NULL){
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
	pointer = ArrayUsers[u].head_queue;
	
	if(pointer ==NULL){
		printf("NULL\n");
	}else{
		while (pointer != NULL){
			printMessage(pointer->item->e , pointer->item->r , pointer->item->text);
			pointer = pointer -> next;
		}
	}
}

void kill(User ArrayUsers){
	int u;
	link pointer;
	scanf("%d",&u);
	pointer = ArrayUsers[u].head_queue;
	
	while(pointer!=NULL){
		deletaMensagem(ArrayUsers, u);
		pointer = ArrayUsers[u].head_queue;
	}
}

void lista(User ArrayUsers, int N_USERS){
	int i;
	link pont;
	for(i=0;i<N_USERS;i++){
		pont = ArrayUsers[i].head_queue;
		if(pont == NULL)
			printf("\nO Utilizador %d nao tem mensagens\n",i);
		while(pont != NULL){
			printf("\nUtilizador %d\n",i);
			printf("De: %d\nPara: %d\nMensagem: %s\n", pont->item->e , pont->item->r, pont->item->text);
			pont = pont -> next;
		}
	}
}

/***************MAIN***************/

int main()
{
	int N_USERS;
	char input[MAXINPUT];
	User ArrayUsers;
	printf("Introduza o numero de utilizadores: ");
	scanf("%d", &N_USERS);
	ArrayUsers  = calloc(N_USERS, sizeof(struct user));
		
	printMenu();
	while (1) {
		scanf("%s",input);
		if (strcmp(input,"send") == 0) 
			send(ArrayUsers);

		
		if (strcmp(input,"lista") == 0) 
			lista(ArrayUsers,N_USERS);
			
		if (strcmp(input,"process") == 0) {
			process(ArrayUsers);
		}
		if (strcmp(input,"list") == 0) {
			list(ArrayUsers);
		}
		if (strcmp(input,"kill") == 0) {
			kill(ArrayUsers);
		}/*
		if (strcmp(input,"kill") == 0) {
			kill();
			break;
		} */
		
		if (strcmp(input,"quit") == 0) {
			free(ArrayUsers);
			return EXIT_SUCCESS;
		} 
	
	}
	free(ArrayUsers);
	return EXIT_FAILURE;
}

