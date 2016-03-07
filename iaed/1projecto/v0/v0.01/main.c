#include <stdio.h>

/* directivas de pre-compilador, definicao de constantes, etc. */

#define N_ESTADOS_MEMBROS 28

int num_votos, EM, PPE;


/* prototipos: */

void adicionaVotos(int EM, int PPE, int num_votos);
int deputadosEleitosEM(int EM);
int deputadosEleitosUE(int EM);
void inicializaPPE();


/* MAIN */

int main() {
    char command;  
	inicializaPPE();
    /* se for o caso, chamar as funcoes de inicializacao aqui */

    while (1) { 
		command = getchar();
        switch (command) {
        case '+':
			scanf(" %d %d %d",&EM, &PPE, &num_votos); 
			adicionaVotos(EM, PPE, num_votos);
            break;
            
        case 'm':
			scanf(" %d", &EM);
			deputadosEleitosEM(EM);
            break;
            
        case 'e':
			scanf(" %d", &EM);
			deputadosEleitosUE(EM);
            break;
            
        case 'x':
			return 0;
			
        default:
            printf("ERRO: Comando desconhecido\n");
        }
        getchar(); /* le o '\n' introduzido pelo utilizador */
    }
    return -1;
}

/* funcoes */

void adicionaVotos(int EM, int PPE, int num_votos) {
}

int deputadosEleitosEM(int EM) {
	int i;
	printf("   ");
	for (i = 0; i < PPE; i++) {
		printf("...");
	}
	return 1;
}

int deputadosEleitosUE(int EM) {
	return 1;
}

/*
void inicializaPPE() {
	for (i = 0; i < PPE; i++) {
		PPE[i] =
*/
