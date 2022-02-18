#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vetor{
	int chave;
	void *prox;	//curioso, tipo void não armazena nada, apenas endereço, https://www.vivaolinux.com.br/artigo/Ponteiros-void-na-linguagem-C
	int v[25];
};

typedef struct vetor v1;
v1 *comeco, *varrer,*auxiliar,*anterior;

void mover(int a, int b, char comando2[6], int n){
	int i,j,temp;
	//char sobre1[6],acima1[6];
	char sobre1[6] = " ";  //veja incializei com carcter espaço = " "
	char acima1[6] = " ";  //veja incializei com carcter espaço = " "
	strcpy(sobre1,"sobre");  //acho que deveria incializar o sobre1 e acima1 primeiro 
	strcpy(acima1,"acima");
	if(a!=b){
			if(strcmp(comando2,sobre1)==0){
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=b){ // pela lógica acho que deveria ser if, se não for if, então deveria a ter um i++ dentro do while
					if(varrer->v[i]!=b){
						varrer=varrer->prox;
					}
					if(varrer->v[i]==b){
						for(j=i;j<n;j++){
							temp=varrer->v[j];
							varrer->v[j]=a;
							a=temp;
						}
					}
				}
			}
			else if(strcmp(comando2,acima1)==0){
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=b){
					if(varrer->v[i]!=b){  //pela lógica acho que deveria ser if
						varrer=varrer->prox;
					}
					if(varrer->v[i]==b){
						for(j=0;j<n;j++){
							temp=varrer->v[j];
							varrer->v[j]=a;
							a=temp;
						}
					}
				}
			}
	}
	/*else{  //desnecessário veja que a função é void, não precisa retornar nada 
		return;
	}*/
}
void pilha(int a,int b,char comando2[6],int n){
	int temp[n],i,j,k,c,cont=0;
	//char sobre1[6],acima1[6];
	char sobre1[6] = " ";  
	char acima1[6] = " ";  
	strcpy(sobre1,"sobre");
	strcpy(acima1,"acima");
	int cont2=0;
		if(a!=b){
			if(strcmp(sobre1,comando2)==0){
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=a){   //pela lógica acho que deveria ser um if
					if(varrer->v[i]!=a){		//mas se quiser varer todo o v[i], então coloque outra variável j=i, e incremente o j++
						varrer=varrer->prox;
					}
					if(varrer->v[i]==a){
						j=i;
						for(k=0;k<n;k++){
							if(j<n){
								temp[k]=varrer->v[j];
								j++;
								cont++;
							}
						}
					}
				}
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=b){
					if(varrer->v[i]!=b){
						varrer=varrer->prox;
					}
					if(varrer->v[i]==b){
						for(k=0;k<cont;k++){
							if(i<n){
								c=varrer->v[i];
								varrer->v[i]=temp[k];
								temp[k]=c;
								i++;
								cont2++;
							}
						}
					}
				}
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=b){
					if(varrer->v[i]!=b){
						varrer=varrer->prox;
					}
					if(varrer->v[i]==b){
						j=i+c+1;
						for(k=0;k<cont;k++){
							if(j<n){
								varrer->v[j]=temp[k];
								j++;
							}
						}
					}
				}
			}else if(strcmp(comando2,acima1)==0){
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=a){
					if(varrer->v[i]!=a){
						varrer=varrer->prox;
					}
					if(varrer->v[i]==a){
						j=i;
						for(k=0;k<n;k++){
							if(j<n){
								temp[k]=varrer->v[j];
								j++;
								cont++;
							}
						}
					}
				}
				varrer=comeco;
				for(i=0;i<n;i++){
					//while(varrer->v[i]!=b){
					if(varrer->v[i]!=b){
						varrer=varrer->prox;
					}
					if(varrer->v[i]==b){
						j=0;
						for(k=cont;k>0;k--){
							if(j<n){
								c=varrer->v[j];
								varrer->v[j]=temp[k];
								temp[k]=c;
								j++;
							}
						}
					}
				}
			}
		}
		
		/*else{		//desnecessário
			return;
		}*/
}
void magica(){
	int n,i,a,b,cont3;
	char comando1[6],comando2[6],pilha1[6],mover1[6],sobre1[6],acima1[6],final[6];
	strcpy(pilha1,"pilha");
	strcpy(sobre1,"sobre");
	strcpy(acima1,"acima");
	strcpy(mover1,"mover");
	strcpy(final,"final");
	scanf("%d",&n);
	cont3=0;
	comeco=NULL;
	do{
		varrer=comeco;
		for(i=0;i<n;i++){
			auxiliar=(v1 *) malloc(sizeof(v1));
			auxiliar->chave=i;
			auxiliar->v[0]=i;
			auxiliar->prox=NULL;
			if(comeco==NULL){ 
				auxiliar->prox=NULL;
				comeco=auxiliar;
			}else{
				varrer=comeco->prox;
				anterior=comeco;
				if(varrer==NULL){
					anterior->prox=auxiliar;
					auxiliar->prox=varrer;
				}else{
					while(varrer!=NULL){
						anterior=varrer;
						varrer=varrer->prox;
					}
				anterior->prox=auxiliar;
				auxiliar->prox=varrer;
				}
			}
		}
		scanf("%s",comando1);
		scanf("%d",&a);
		scanf("%s",comando2);
		scanf("%d",&b);
		printf("Leitura: %s %d %s %d\n",comando1,a,comando2,b);
		if(strcmp(mover1,comando1)==0){
			mover(a,b,comando2,n);
		}else if(strcmp(pilha1,comando1)==0){
			pilha(a,b,comando2,n);
		}
		for(i=0;i<6;i++){
			if(strcmp(comando1,final)==0){
				cont3++;
			}
		}	
	}while(cont3!=0);
}
int main(int argc, char **argv)
{
	int i=0;
	
	magica();
	
	varrer=comeco;
	do{
		printf("%d: %d\n",varrer->chave,varrer->v[i]);
		varrer=varrer->prox;
		i++;
	}while(varrer->prox!=NULL);
	
	varrer=comeco;
	while(varrer->prox!=NULL){
		anterior=varrer;
		varrer=varrer->prox;
		if((varrer->prox==NULL)&&(varrer!=comeco)){
			free(varrer);
			varrer=comeco;
			anterior->prox=NULL;
		}
	}	
	if(varrer->prox==NULL){
		free(varrer);	
		varrer=NULL;
		anterior=NULL;
		comeco=NULL;
	}	
	if(comeco==NULL){
		anterior=NULL;
		varrer=NULL;
		auxiliar=NULL;
	}
	
	return 0;
}

