/* 		PROJECTO 2 - final.c
 * 
 * 78093 - Goncalo Santos
 * 78328 - Pedro Duarte
 * 79112 - Goncalo Fialho
 * 
 * */

#include "final.h"


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
			
		if (strcmp(input,"process") == 0) {
			scanf("%d",&u);
			process(ArrayUsers,u);
		}
			
		if (strcmp(input,"list") == 0) {
		 	scanf("%d",&u);
			list(ArrayUsers,u);
		}

		if (strcmp(input,"kill") == 0){
			scanf("%d",&u);
			kill(ArrayUsers,u);
		}
		if (strcmp(input,"listsorted") == 0)  {
			scanf("%d", &u);
			listSorted(ArrayUsers,u);
		}
	
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

/**************FUNCOES**************/

Item criaMensagem(int sender, int receiver, char *texto){
	/*Cria o item com a mensagem texto do utilizador sender para o receiver*/
	Item msg;
	msg = malloc(sizeof(struct mensagem));
	msg -> e = sender;
	msg -> r = receiver;
	msg -> text = (char*) malloc( (strlen(texto)+1) * sizeof(char) );
	strcpy(msg->text,texto);
	return msg;
}

link criaNode(Item msg){
	/*Cria um novo node com a mensagem msg*/
	link new_node;
	new_node = malloc(sizeof(struct node));
	new_node -> item = msg;
	new_node -> next = NULL;
	return new_node;
}

void printMessage(int e, int r, char *text){
	/*Escreve no stdout a mensagem text enviada por e para o utilizador r*/
	printf("%d %d %s",r,e,text);
}

int isEmpty(User ArrayUsers, int u) {
	/*Verifica se a fila do utilizador u esta vazia*/
	return (ArrayUsers[u].head_queue == NULL);
}

void deletaMensagem(User ArrayUsers, int u){
	/*Apaga a primeira mensagem do utilizador u*/
	link aux;	
	free(ArrayUsers[u].head_queue -> item -> text);
	free(ArrayUsers[u].head_queue -> item);
	aux = ArrayUsers[u].head_queue -> next;
	free(ArrayUsers[u].head_queue);
	ArrayUsers[u].head_queue = aux;
}

int compare(const void *p1, const void *p2) {
	/*Compara dois itens consecutivos; usada pela funcao qsort()*/
	int resultado;
	Item ip1 = *(Item *)p1;
	Item ip2 = *(Item *)p2;
	resultado  = strcmp(ip1->text,ip2->text);
	if(resultado) 				
		return resultado;
	return (ip1->e - ip2->e);
}

/*************COMANDOS*************/

void send(User ArrayUsers) {
	/*Le a mensagem do utilizador sender e envia-a para o utilizador receiver*/
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



void process(User ArrayUsers, int u){
	/*Processa todas as mensagens do utilizador u*/
		
	if(!(isEmpty(ArrayUsers, u))){
		printMessage(ArrayUsers[u].head_queue->item->e ,ArrayUsers[u].head_queue->item->r , ArrayUsers[u].head_queue->item->text);
		deletaMensagem(ArrayUsers,u);
	}else{
		printf("NULL\n");
	}
}


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

void kill(User ArrayUsers,int u){
	/*Apaga todas as mensagens da fila do utilizador u*/
	link pointer;
	pointer = ArrayUsers[u].head_queue;
	
	while(pointer != NULL){
		deletaMensagem(ArrayUsers, u);
		pointer = ArrayUsers[u].head_queue;
	}
}


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
