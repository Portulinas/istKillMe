/* Grupo 003
 * 
 * Goncalo Fialho n79112
 * Goncalo Santos n78093
 * Pedro Santos   n78328
 * 
 */

#include <stdio.h>
#include "prot.h"

/* directivas de pre-compilador, definicao de constantes, etc. */
#define NUM_PARTIDOS 12
#define NUM_PAISES 28
#define VOTACAO 2
	
char paises[NUM_PAISES][3] = {"DE","AT","BE","BG","CY","HR","DK","SK","SI","ES","EE","FI","FR","GR","HU","IE","IT","LV","LT","LU","MT","NL","PL","PT","GB","CZ","RO","SE"};
char partidos[NUM_PARTIDOS][4] = {"EPP","PES","LDE","EGP","ECR","ELP","ELD","EDP","EAF","EMN","ECP","AED"};

int num_deputados[NUM_PAISES] = {96,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};
int num_votos, EM, PPE;
int eleitos[NUM_PAISES][NUM_PARTIDOS];

float votos[NUM_PAISES][NUM_PARTIDOS][VOTACAO];  /* 2 arrays (Votos iniciais e quocientes)   */


/* MAIN */

int main() {
    char command;  
    while (1) { 
		command = getchar();
        switch (command) {
        case '+':
			scanf(" %d %d %d",&EM, &PPE, &num_votos); 
			adicionaVotos(EM, PPE, num_votos);
			metodo(EM-1);
            break;
            
        case 'm':
			scanf(" %d", &EM);
			deputadosEleitosEM(EM-1);
            break;
            
        case 'e':
			deputadosEleitosUE();
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


/* Adiciona votos (num_votos) a um partido (PPE) de um determinado pais (EM) */
void adicionaVotos(int EM, int PPE, int num_votos) {
	int i;

	for(i=0;i<NUM_PARTIDOS;i++){ /*Percorre todos os Partidos do EM e coloca os quocientes iguais aos votos iniciais */
		votos[EM-1][i][1] = votos[EM-1][i][0];
	}
	votos[EM-1][PPE-1][0] = votos[EM-1][PPE-1][0] + num_votos;
	votos[EM-1][PPE-1][1] = votos[EM-1][PPE-1][0] ;
}


/* Imprime os resultados de um pais (EM) */
void deputadosEleitosEM(int EM){
	int i;
	
	printf("  ");
	for(i=0;i < NUM_PARTIDOS;i++)
		printf(" %s",partidos[i]);
	printf("\n");
	
	printf("%s",paises[EM]);
	for(i=0;i < NUM_PARTIDOS;i++){
		printf(" %3d",eleitos[EM][i]); 
	}
	printf("\n");
}

/* Imprime os resultados de todos os paises da UE */
void deputadosEleitosUE(){
	int soma;
	int i,j;
	
	printf("  ");
	for(i=0;i<NUM_PARTIDOS;i++)
		printf(" %s",partidos[i]);
	
	printf("\n");
	
	for(i=0;i<NUM_PAISES;i++){
		printf("%s",paises[i]);
		for(j=0;j<NUM_PARTIDOS;j++){
			printf(" %3d",eleitos[i][j]);
		}
		printf("\n");
	}
	
	printf("TE");
		
	for(i=0;i<NUM_PARTIDOS;i++){
		soma = 0;
		for(j=0;j<NUM_PAISES;j++){
			soma = soma + eleitos[j][i];
		}
		printf(" %3d",soma);
	}
	printf("\n");
}

/* Realiza o metodo d'Hont para um pais (EM) */ 
void metodo(int EM){
	int p = 0;
	int i; 
	int deputados = num_deputados[EM];
	
	/* Limpa os resultados dos deputados eleitos do EM */
	for(i=0;i < NUM_PARTIDOS;i++){
		eleitos[EM][i] = 0;
	}
	
	while(deputados != 0){
		float m = 0;  		/* Guarda o maior quociente de todos os partidos do EM */
		
		/* Verifica qual deve ser o partido que ganha um deputado e guarda o seu indice em p */
		for(i=0;i<NUM_PARTIDOS;i++){
			if(votos[EM][i][1] == m){  					/*se quociente do partido do estado membro igual ao maior quociente*/
				if(eleitos[EM][i] < eleitos[EM][p]){	/*e se o num de deputados do partido for menor ao numero de deputados do partido que e suposto ganhar um deputado */
					m = votos[EM][i][1] ;				/*guarda o novo maior quociente*/
					p = i;								/*guarda o novo "maior" partido*/
				}					
			}else if(votos[EM][i][1] > m){				/*se o quociente do partido do estado membro for maior que o maior quociente*/
				m = votos[EM][i][1] ;					/*guarda o novo maior quociente*/
				p = i;									/*guarda o novo "maior" partido*/
			}
		}
		
		eleitos[EM][p] = eleitos[EM][p] + 1;			/*no fim, adiciona um deputado ao "maior" partido*/
		
		deputados = deputados - 1;						/*retira um deputado a esse estado membro*/
		votos[EM][p][1] = votos[EM][p][0] / (eleitos[EM][p] + 1);	/*divide-se o numero de votos desse partido pelo numero de deputados eleitos+1
																	e altera-se o quociente para esse valor*/	
	}	
}
