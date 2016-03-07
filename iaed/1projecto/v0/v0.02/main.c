#include <stdio.h>

/* directivas de pre-compilador, definicao de constantes, etc. */
#define NUM_PARTIDOS 12
#define NUM_PAISES 28

int votos[NUM_PAISES][NUM_PARTIDOS];
	
char paises[NUM_PAISES][3] = {"DE","AT","BE","BG","CY","HR","DK","SK","SI","ES","EE","FI","FR","GR","HU","IE","IT","LV","LT","LU","MT","NL","PL","PT","GB","CZ","RO","SE"};
char partidos[NUM_PARTIDOS][4] = {"EPP","PES","LDE","EGP","ECR","ELP","ELD","EDP","EAF","EMN","ECP","AED"};

int num_deputados[NUM_PAISES] = {96,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};




int num_votos, EM, PPE;


/* prototipos: */

void adicionaVotos(int EM, int PPE, int num_votos);
void deputadosEleitosEM(int EM);
void deputadosEleitosUE();
void inicializaPPE();


/* MAIN */

int main() {
    char command;  
	/*inicializaPPE();*/
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

void adicionaVotos(int EM, int PPE, int num_votos) {
}

void deputadosEleitosEM(int EM){
	int i;
	printf("\t");
	for(i=0;i<NUM_PARTIDOS;i++)
		printf("%s\t",partidos[i]);
	printf("\n");
	printf("%s\t",paises[EM]);
	for(i=0;i<NUM_PARTIDOS;i++){
		printf("%3d\t",votos[EM][i]);
	}
	printf("\n");

}


void deputadosEleitosUE(){
	int i,j;
	
	printf("\t");
	for(i=0;i<NUM_PARTIDOS;i++)
		printf("%s\t",partidos[i]);
	
	printf("\n");
	
	for(i=0;i<NUM_PAISES;i++){
		printf("%s\t",paises[i]);
		for(j=0;j<NUM_PARTIDOS;j++){
			printf("%3d\t",votos[i][j]);
		}
		printf("\n");
	}	

	
}

