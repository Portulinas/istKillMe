/*
 * Goncalo Fialho / n179112 - <file name>.c 
 * Instituto Superior Técnico
 */


#include <stdio.h>

#define NUM_PARTIDOS 12
#define NUM_PAISES 28
#define VOTACAO 2


/*int votos[NUM_PAISES][NUM_PARTIDOS];*/
	
char paises[NUM_PAISES][3] = {"DE","AT","BE","BG","CY","HR","DK","SK","SI","ES","EE","FI","FR","GR","HU","IE","IT","LV","LT","LU","MT","NL","PL","PT","GB","CZ","RO","SE"};
char partidos[NUM_PARTIDOS][4] = {"EPP","PES","LDE","EGP","ECR","ELP","ELD","EDP","EAF","EMN","ECP","AED"};

int num_deputados[NUM_PAISES] = {7,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};

 
int votos[NUM_PAISES][NUM_PARTIDOS][VOTACAO];
int eleitos[NUM_PAISES][NUM_PARTIDOS];
int m,p = 0;

int main()
{
	int i; 
	int j;
	
	for(i=0;i<4;i++){
		printf("%s ",partidos[i]);
		scanf("%d",&votos[0][i][0]);
		votos[0][i][1] = votos[0][i][0];
	}
	
	while(num_deputados[0] != 0){
		printf("Ciclo: %d\n",7-num_deputados[0]);
		m = 0;
		for(i=0;i<NUM_PARTIDOS;i++){

			if(votos[0][i][1] == m){
				if(eleitos[0][i]<m){
					m = votos[0][i][1] ;
					p = i;
				}
					
			}else if(votos[0][i][1] > m){				
				m = votos[0][i][1] ;
				p = i;
			}
		}
		
		eleitos[0][p] = eleitos[0][p] + 1;
		
		num_deputados[0] = num_deputados[0] - 1;
		
		votos[0][p][1] = votos[0][p][0]/ (eleitos[0][p] + 1);
		printf("\tPartido Vencedor %s: %d\n\tDeputados do partido eleitos: %d\n\tTotal de deputados eleitos: %d\n",partidos[p],votos[0][p][1],eleitos[0][p],7-num_deputados[0]);


		
	}	
	
	
	printf("País %s: \n",paises[0]);
	for(j=0;j<NUM_PARTIDOS;j++){
		printf(" ");
		printf("Votos iniciais partido %s: %d\t\t finais: %d\teleitos: %d\n",partidos[j],votos[0][j][0],votos[0][j][1],eleitos[0][j]);
	}
	
	return 0;
}

