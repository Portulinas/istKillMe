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

typedef struct queue {
	link head, tail;
}*Queue;


/**************FUNCOES**************/



Item newItem(char *message, int sender, int receiver) { 
		Item new = malloc(sizeof(Item));
		new->e = sender;
		new->r = receiver;
		new->text = (char*)malloc(strlen(message) * sizeof(char));
		strcpy(new->text,message);
		return new;
}

void deleteItem(Item x) {
	/*liberta memoria alocada*/
}

void showItem(Item x) {
	/*mostra o conteudo de um item*/
}

int cmpItem(Item a, Item b) {
	/*retorna um valor :
	<0 se a < b; 
	=0 se a = b;
	>0 se a > b.*/
	return 0;
}


void printMenu() {
	printf("\t******** Comandos ********\n\n");
	printf("send e r info - regista a mensagem info enviada pelo emissor e para o utilizador r. Limite 500 caracteres (incluindo espacos).\n");
	printf("process u - imprime a proxima mensagem para utilizador u.\n");
	printf("list u - lista as mensagens em espera para o utilizador u por ordem de chegada.\n");
	printf("listsorted u - list por ordem alfabetica.\n");
	printf("kill u - apaga todas as mensagens em espera do utilizador u.\n");
	printf("quit - apaga todas as mensagens em espera e sai do programa.\n");
}

int isEmpty(Queue Users, int user) {
	return (Users[user].head == NULL);
}

link insertEnd(link tail, Item new_item, link new_node) {
	new_node->next = tail->next;
	new_node->item = new_item;
	tail = new_node;
	return tail;
}

void send(Queue Users) {
	char input[CRCTRS];
	int sender, receiver;
	link new_node = malloc(sizeof(struct node));
	link last; /*apontador para o ultimo elemento da fila*/
	link start; /*apontador para o primeiro elemento da fila*/
	Item new_item;
	
	scanf("%d%d ", &sender, &receiver); /*guarda o 'e' e o 'r'*/
	fgets(input, CRCTRS, stdin); /*guarda o texto da mensagem em input*/
	
	last = Users[receiver].tail;
	start = Users[receiver].head;
	new_item = newItem(input, sender, receiver);
	
	if (isEmpty(Users, receiver)) {
		new_node->next = start;	
	}
	else
		last = insertEnd(last, new_item, new_node);
	
	printf("%s",last->item->text);
}

void process() {
	
}

void initializeUsers(Queue Users, int N_USERS) {
	int i;
	for (i = 0; i < N_USERS; i++) {
		Users[i].head = NULL;
		Users[i].tail = NULL;
	}
}

int main() {
	int N_USERS;
	char input[MAXINPUT];
	Queue Users;
	printf("Introduza o numero de utilizadores: ");
	scanf("%d", &N_USERS);
	Users  = malloc(N_USERS * sizeof(struct queue));
	initializeUsers(Users, N_USERS);
	printMenu();
	
	while (1) {
		/*menu*/
		scanf("%s ",input);
		if (strcmp(input,"send") == 0) {
			send(Users);
			break;
		}	
		if (strcmp(input,"process") == 0) {
			process();
			break;
		}
	/*	if (strcmp(input,"listsorted") == 0) {
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
		if (strcmp(input,"quit") == ) {
			quit();
			return 0;
		} */
	}
	free(Users);
	return -1;
}
