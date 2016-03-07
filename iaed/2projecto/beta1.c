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
}User;
/**************FUNCOES**************/
int N_USERS;
/*char input[MAXINPUT];*/
User *arrayUsers;
Item *msg;



void printMenu() {
	printf("\t******** Comandos ********\n\n");
	printf("send e r info - regista a mensagem info enviada pelo emissor e para o utilizador r. Limite 500 caracteres (incluindo espacos).\n");
	printf("process u - imprime a proxima mensagem para utilizador u.\n");
	printf("list u - lista as mensagens em espera para o utilizador u por ordem de chegada.\n");
	printf("listsorted u - list por ordem alfabetica.\n");
	printf("kill u - apaga todas as mensagens em espera do utilizador u.\n");
	printf("quit - apaga todas as mensagens em espera e sai do programa.\n");
}



void criaMensagem(int from,int to){
	link *i;
	link *no;
	no = (link*) malloc(sizeof(link));

	msg = (Item*) malloc(sizeof(Item));
	
	no -> item = msg;
	no -> next = NULL;	
	
	printf("\n\n####################################\n\n");
	
		
	printf("Executa criaMensagem(%d,%d)\n",from,to);
	
	if(arrayUsers[to].head_queue==NULL){
		arrayUsers[to].head_queue = no;
	}else{
		i = arrayUsers[to].head_queue;
		while(i->next != NULL){
			i = i->next;
			
		}
		i -> next = no;
	}

	
	printf("No criado em %p!\nItem -> %p\nNext -> %p\n\n",arrayUsers[to].head_queue, no->item,no->next);
	
		
	printf("\n\n####################################\n\n");
	
	i = arrayUsers[to].head_queue;
	printf("Nos existentes\n");
	while(i!=NULL){
		printf("No em %p\nItem -> %p\nNext -> %p\n\n",i,i->item,i->next);
		i = i->next;	
}

	/*
	msg -> item -> e = from;
	msg -> item -> r = to;

	if(arrayUsers[to].head_queue==NULL)
		arrayUsers[to].head_queue = msg;
		
	printf("\n%p\n",arrayUsers[to].head_queue);


	printf("\n%d\n",msg -> item -> e);
	printf("\n%d\n",msg -> item -> r);
*/
}
/*
void mostraMensagem(int user1){
	if(arrayUsers[user1].head_queue == NULL){
		printf("Utilizador sem mensagens!");
	}else{
		while()
		
	}
		
}*/

int main() {
	
	int i;
	printf("Introduza o numero de utilizadores: ");
	scanf("%d", &N_USERS);
	arrayUsers  = (User*) calloc(N_USERS , sizeof( User));



	for (i = 0; i < N_USERS; i++) {
		printf("User[%d].head = %p\n",i,arrayUsers[i].head_queue);
	}
	printf("\n");
	
	printf("Sizeof(Link) = %d\n",sizeof(link));
	printf("Sizeof(Item) = %d\n",sizeof(Item));	 
	printf("Sizeof(User) = %d\n",sizeof(User));
	printf("Sizeof(int) = %d\n",sizeof(int));
	printf("\n");
	

	criaMensagem(1,1);
	criaMensagem(0,2);
	criaMensagem(1,2);
	criaMensagem(0,2);
	criaMensagem(1,1);
	criaMensagem(0,1);
	
	for (i = 0; i < N_USERS; i++) {
		printf("User[%d].head = %p\n",i,arrayUsers[i].head_queue);
	}

	
	/*
	criaMensagem(1,0);

	for (i = 0; i < N_USERS; i++) {
		printf("User[%d].head = %p\n",i,arrayUsers[i].head_queue);
	}
	
	printf("\n\n");
	
	
	*/
	/*printMenu();*/
	
	
	/*
	
	while (1) {
	
		scanf("%s ",input);
		if (strcmp(input,"send") == 0) {
			break;
		}	
		if (strcmp(input,"process") == 0) {

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
		} 
	}*/
	free(arrayUsers);
	return 0;
}
