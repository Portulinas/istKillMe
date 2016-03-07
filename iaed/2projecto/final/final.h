#ifndef PROJ_H
#define PROJ_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRCTRS 501
#define MAXINPUT 11

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



Item criaMensagem(int sender, int receiver, char *texto);
link criaNode(Item msg);
int isEmpty(User ArrayUsers, int u);
void deletaMensagem(User ArrayUsers, int u);
int compare(const void *p1, const void *p2);
void send(User ArrayUsers);
void process(User ArrayUsers, int u);
void list(User ArrayUsers, int u);
void kill(User ArrayUsers,int u);
void listSorted(User ArrayUsers, int u);

#endif
