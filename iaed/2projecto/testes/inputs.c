#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct mensagem{
	char msg[100];
	int from;
	int receiver;
}Mensagem;


typedef struct user{
	int *head;
}User;



User *utilizadores;
int N_USERS;

void ponteiro(){
	int a,b;
	int *ponteiro_a = &a;
	int *ponteiro_b = &b;
	*ponteiro_a = 5;
	*ponteiro_b = 10;
	printf("%d\n%d\n",ponteiro_a,ponteiro_b);
}


void listaUsers(){
	int *vec;
	int i,NUM;
		
	printf("Num de Users: ");
	scanf("%d",&NUM);

	vec = (int*) malloc(sizeof(int)*NUM);
	for(i=0;i<NUM;i++)
		scanf("%d",&vec[i]);
	
	for(i=0;i<NUM;i++)
		printf("%d\n",vec[i]);
		
	free(vec);
}
/*
void criaMensagem(){
	Mensagem x;
	strcpy(x.msg,"test");
	x.from = 1;
	x.receiver = 2;
	printf("De: %d\nPara: %d\nMensagem: %s\n",x.from,x.receiver,x.msg);

}*/


void criaUtilizadores(){
	int i;


	scanf("%d",&N_USERS);
	utilizadores = (User*) malloc(sizeof(User)*N_USERS);
	for(i=0;i<N_USERS;i++)
		utilizadores[i].head = NULL;
		
	for(i=0;i<N_USERS;i++)
		printf("%d\n",utilizadores[i].head);
		
}


void criaMensagem(int from, int to){
	if(utilizadores[to].head == NULL)
		printf("esta NULL\n");

}

int main()
{
	int a=4;
	/*ponteiro();
	listaUsers();
	criaMensagem();*/
	criaUtilizadores();

	criaMensagem(1,2);
	
	utilizadores[2].head = &a;
	printf("NOVA HEAD\n");
	criaMensagem(1,2);
	printf("%d\n",utilizadores[2].head);
	
	
	free(utilizadores);
	return 0;
}

