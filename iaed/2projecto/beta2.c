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
}Item;

typedef struct node {
	Item *item;
	struct node *next;
}link;


typedef struct user {
	link *head_queue;
	link *tail_queue;	
}User;
/**************FUNCOES**************/

/*char input[MAXINPUT];*/




void printMenu() {
	printf("\t******** Comandos ********\n\n");
	printf("send e r info - regista a mensagem info enviada pelo emissor e para o utilizador r. Limite 500 caracteres (incluindo espacos).\n");
	printf("process u - imprime a proxima mensagem para utilizador u.\n");
	printf("list u - lista as mensagens em espera para o utilizador u por ordem de chegada.\n");
	printf("listsorted u - list por ordem alfabetica.\n");
	printf("kill u - apaga todas as mensagens em espera do utilizador u.\n");
	printf("quit - apaga todas as mensagens em espera e sai do programa.\n");
}

int isEmpty(User queue, int receiver) {
	return (queue[receiver].head_queue == NULL);
}


void criaMensagem(int sender,int receiver){
	link *i;
	link *no;
	no = malloc(sizeof(struct node));
	msg = malloc(sizeof(struct mensagem));
	no->item = msg;
	no->next = NULL;		
		
	printf("Executa criaMensagem(%d,%d)\n",sender,receiver);
	
	if(ArrayUsers[receiver].head_queue==NULL){
		ArrayUsers[receiver].head_queue = no;
	}else{
		i = ArrayUsers[receiver].head_queue;
		while(i->next != NULL){
			i = i->next;
			
		}
		i -> next = no;
	}

	
		
	printf("\n\n####################################\n\n");
	
	i = ArrayUsers[receiver].head_queue;
	printf("Nos existentes\n");
	while(i!=NULL){
		i = i->next;	
}

	/*
	msg -> item -> e = from;
	msg -> item -> r = to;

	if(ArrayUsers[to].head_queue==NULL)
		ArrayUsers[to].head_queue = msg;
		
	printf("\n%p\n",ArrayUsers[to].head_queue);


	printf("\n%d\n",msg -> item -> e);
	printf("\n%d\n",msg -> item -> r);
*/
}
/*
void mostraMensagem(int user1){
	if(ArrayUsers[user1].head_queue == NULL){
		printf("Utilizador sem mensagens!");
	}else{
		while()
		
	}
		
}*/

void send() {
	char input[CRCTRS];
	int sender, receiver;
	scanf("%d%d ", &sender, &receiver); 	/*guarda o 'e' e o 'r'*/
	fgets(input, CRCTRS, stdin); 			/*guarda o texto da mensagem em input*/
}

int main() {
	int N_USERS;
	char input[MAXINPUT];
	User *ArrayUsers;
	Item *msg;
	printf("Introduza o numero de utilizadores: ");
	scanf("%d", &N_USERS);
	ArrayUsers  = (User*)calloc(N_USERS, sizeof(User));
	printMenu();
	/*criaMensagem(1,1);
	criaMensagem(0,2);
	criaMensagem(1,2);
	criaMensagem(0,2);
	criaMensagem(1,1);
	criaMensagem(0,1);*/
	while (1) {
		scanf("%s ",input);
		if (strcmp(input,"send") == 0) {
			send();
			break;
		}	
/*		if (strcmp(input,"process") == 0) {

			break;
		}
*	if (strcmp(input,"listsorted") == 0) {
			listsorted();
			break;
		}
		if (strcmp(input,"list") == 0) {
			list();
			break;
		}
		if (strcmp(input,"kill") == 0) {
			kill();
			break;
		}
		
		if (strcmp(input,"quit") == 0) {
			return 0;
		} */
	}
	free(ArrayUsers);
	return 0;
}
