/*
 * Goncalo Fialho / n179112 - <file name>.c 
 * Instituto Superior Técnico
 */


#include <stdio.h>

#define NUM_PARTIDOS 12
#define NUM_PAISES 28

int votos[NUM_PAISES][NUM_PARTIDOS];
	
char paises[NUM_PAISES][3] = {"DE","AT","BE","BG","CY","HR","DK","SK","SI","ES","EE","FI","FR","GR","HU","IE","IT","LV","LT","LU","MT","NL","PL","PT","GB","CZ","RO","SE"};
char partidos[NUM_PARTIDOS][4] = {"EPP","PES","LDE","EGP","ECR","ELP","ELD","EDP","EAF","EMN","ECP","AED"};

int num_deputados[NUM_PAISES] = {96,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};



int main()
{
	return 0;
}

void deputadosEleitosEM(){
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
