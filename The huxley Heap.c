
#include <stdio.h>
#include <string.h>

struct loteria{
	char codigo[20];
	int aposta[15];
	int acerto;
};

typedef struct loteria lo;
void ganhou(){
	int n,j,vetor[10], maior,menor,i,aposta[15],c=0,k=0,ganhador=0;
	for(i=0;i<10;i++){
		scanf("%d", &vetor[i]);
	}
	scanf("%d",&n);
	lo vetor2[n];
	for(i=0;i<n;i++){
		scanf("%s",vetor2[i].codigo);
		for(j=0;j<15;j++){
			scanf("%d",&aposta[j]);
			if(aposta[j]==vetor[k]){
				c++;
				k++;
			}
		}
		if(c<=15){
			vetor2[i].acerto=c;
		}
		c=0;
	}
	maior=vetor2[0].acerto;
	menor=vetor2[0].acerto;
	k=0;
	for(i=0;i<n;i++){
		if(maior<=vetor2[i].acerto){
			maior=vetor2[i].acerto;
		}
		if(menor>=vetor2[i].acerto){
			menor=vetor2[i].acerto;
		}
	}
	if(maior==1){
		printf("Faixa: %d acerto\n", maior);
	}else{
		printf("Faixa: %d acertos\n", maior);
	}
	for(i=0;i<n;i++){
		if(vetor2[i].acerto==maior){
			printf("%s\n",vetor2[i].codigo);
			ganhador++;
		}
	}
	if(ganhador==1){
		printf("%d ganhador\n", ganhador);
	}else{
		printf("%d ganhadores\n", ganhador);
	}
	if(menor==1){
		printf("Faixa: %d acerto\n", menor);
	}else{
		printf("Faixa: %d acertos\n", menor);
	}
	ganhador=0;
	for(i=0;i>n;i++){
		if(vetor2[i].acerto==menor){
			printf("%s\n",vetor2[i].codigo);
			ganhador++;
		}	
	}
	if(ganhador==1){
		printf("%d ganhador\n", ganhador);
	}else{
		printf("%d ganhadores\n", ganhador);
	}
}

int main(int argc, char **argv)
{
	ganhou();
	return 0;
}

