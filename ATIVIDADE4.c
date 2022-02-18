
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct listaC{
	char nome[20];
	char sobrenome[20];
	void *proximo;
};
typedef struct listaC Circular;
Circular *comeco, *fim, *varrer, *auxiliar, *anterior;
int cont2=0;
void alterar(){                                      //altera o dado.
	system("clear");
	printf("\n\n\n*** Alterar ***\n\n\n");
	char nome[20],sobrenome[20];
	int c=0,cont=0;
	printf("Digite o nome e sobrenome que deseja alterar: ");
	scanf("%s",nome);
	scanf("%s",sobrenome);
	varrer=comeco;
		while(cont!=0){
			if((strcmp(varrer->nome,nome)==0)&&(strcmp(varrer->sobrenome,sobrenome)==0)){
				printf("%s %s",nome,sobrenome);
				printf("Digite os novos dados (nome e ultimo sobrenome)");
				scanf("%s %s",nome,sobrenome);
				c++;
				printf("\nDado alterado!\n");
			}
			varrer=varrer->proximo;
			if(varrer==comeco){
				cont++;
			}
		}
		if(c!=1){
			printf("Esta pessoa nao esta na lista.\n");
		}	
	}
void consultar(){                                        //Efetua a operação de busca.
	system("clear");
	printf("\n\n\n*** Consultar ***\n\n\n");
	char nome[20],sobrenome[20];
	int c=0,cont=0;
	printf("Digite o nome e sobrenome que deseja consultar: ");
	scanf("%s",nome);
	scanf("%s",sobrenome);
	varrer=comeco;
		while(cont!=0){
			if((strcmp(varrer->nome,nome)==0)&&(strcmp(varrer->sobrenome,sobrenome)==0)){
				printf("%s %s", nome, sobrenome);
				c++;
			}
			varrer=varrer->proximo;
			if(varrer==comeco){
				cont++;
			}
		}while(varrer!=comeco);
		if(c!=1){
			printf("Esta pessoa nao esta na lista.\n");
		}
}
void excluir(){
	system("clear");
	printf("\n\n\n*** Excluir ***\n\n\n");
	char nome[20],sobrenome[20],excluir[2];
	excluir[0]='@';
	int c=0,cont=0;
	printf("Digite o nome e sobrenome que deseja excluir: ");
	scanf("%s",nome);
	scanf("%s",sobrenome);
	varrer=comeco;
		while(cont!=0){
			if((strcmp(varrer->nome,nome)==0)&&(strcmp(varrer->sobrenome,sobrenome)==0)){
				strcpy(varrer->nome,excluir);
				strcpy(varrer->sobrenome,excluir);
				c++;
				printf("\nDado excluido!\n");
			}
			varrer=varrer->proximo;
			if(varrer==comeco){
				cont++;
			}
		}
		if(c!=1){
			printf("Esta pessoa nao esta na lista.\n");
		}
}
//void menu(char operacao){
//	do{
//		if(operacao=='I'){
//			inserir();
//		}else if(operacao=='A'){
//			alterar();
//		}else if(operacao=='C'){
//			consultar();
//		}else if(operacao=='E'){
//			excluir();
//		}
//		system("clear");
//		printf("\n\n\n*** Lista de Espera ***\n\n\n");
//		printf("\nQual operacao deseja efetuar?\n");
//		printf("\nI-Inserir");
//		printf("\nA-Alterar");
//		printf("\nC-Consultar");
//		printf("\nE-Excluir");
//		printf("\nS-Sair\n\n");
//		scanf(" %c",&operacao);
//		operacao=toupper(operacao);
//	}while(operacao!='S');
//}
void inserir(){
	char nome[20], sobrenome[20],excluso[2],r='S',operacao;
	int cont=0;
	excluso[0]='@';
	if(cont2==0){
		comeco=NULL;
		fim=comeco;
	}
	while(r=='S'){
		system("clear");                                                  //Limpa a tela.
		printf("\n\n\n*** Lista de Espera ***\n\n\n");
		system("clear"); 
		printf("\n\n\n*** Inserir ***\n\n\n");
		printf("Digite os dados do paciente:\n");
		varrer=comeco;
		if(varrer==NULL){
			cont++;
		}
		while(cont!=1){                                                   //Varre a estrutura e mostra dados anteriores
			if(strcmp(varrer->nome,excluso)!=0){
				printf("\n");                                             //se houverem.
				printf(" - %s ",varrer->nome);
				printf("%s - ",varrer->sobrenome);
				printf("\n");
			}
			varrer=varrer->proximo;
			if(varrer==comeco){
				cont++;
			}
		}
		auxiliar=(Circular *) malloc(sizeof(Circular));                   //Aloca o espaço para a nova variável dinâmica.
		printf("\nNome e ultimo sobrenome: ");
		scanf("%s",nome);
		scanf("%s",sobrenome);
		//varrer=comeco;
		cont=0;
		if(varrer==NULL){
			cont++;
		}
		while(cont!=1){                                                   //Valida os dados, para que não haja ambiguidade (strcmp compara strings).
			if((strcmp(varrer->nome,nome)==0)&&(strcmp(varrer->sobrenome,sobrenome)==0)){
				printf("\nEsta pessoa ja esta na lista, digite novamente nome e ultimo sobrenome: ");
				scanf("%s",nome);
				scanf("%s",sobrenome);
			}
			if(varrer==comeco){
				cont++;
			}
		varrer=varrer->proximo;
		}
		strcpy(auxiliar->sobrenome,sobrenome);               //Copia os dados para a nova variável.
		strcpy(auxiliar->nome,nome);                         //Copia uma string para outra.
		auxiliar->proximo=comeco;
		if(comeco==NULL){                                    //Insere a nova variável na estrutura dinâmica. 
			comeco=auxiliar;
			auxiliar->proximo=comeco;
			fim=auxiliar;
		}else{
			fim->proximo=auxiliar;
			fim=auxiliar;
		}
		system("clear");                                     //Limpa a tela novamente.
		printf("\n\n\n*** Lista de Espera ***\n\n\n");       //Mostra a lista de espera.
		varrer=comeco;
		cont=0;
		while(cont!=1){
			printf("\n\n");
			printf(" - %s ",varrer->nome);
			printf("%s - ",varrer->sobrenome);
			printf("\n");
			varrer=varrer->proximo;
			if(varrer==comeco){
				cont++;
			}
		}
		cont=0;
		printf("\nContinuar listando? S/N\n");       //Pergunta se novos dados serão inseridos.
		scanf(" %c",&r);
		r=toupper(r);                                //Torna o caractere maiúsculo.
	}
	cont2++;
	do{
		system("clear");
		printf("\n\n\n*** Lista de Espera ***\n\n\n");
		printf("\nQual operacao deseja efetuar?\n");
		printf("\nI-Inserir");
		printf("\nA-Alterar");
		printf("\nC-Consultar");
		printf("\nE-Excluir");
		printf("\nS-Sair\n\n");
		scanf(" %c",&operacao);
		operacao=toupper(operacao);
		if(operacao=='I'){
			inserir();
		}else if(operacao=='A'){
			alterar();
		}else if(operacao=='C'){
			consultar();
		}else if(operacao=='E'){
			excluir();
		}
	}while(operacao!='S');
}
int main(int argc, char **argv)
{
	comeco=NULL;
	varrer=comeco;
	system("clear");
	inserir();
	//	system("clear");
//		printf("\n\n\n*** Lista de Espera ***\n\n\n");
//		printf("\nQual operacao deseja efetuar?\n");
//		printf("\nI-Inserir");
//		printf("\nA-Alterar");
//		printf("\nC-Consultar");
//		printf("\nE-Excluir");
//		printf("\nS-Sair\n\n");
//		scanf(" %c",&operacao);
//		operacao=toupper(operacao);
//		if(operacao=='I'){
//			inserir();
//		}else if(operacao=='A'){
//			alterar();
//		}else if(operacao=='C'){
//			consultar();
//		}else if(operacao=='E'){
//			excluir();
//		}
//	}while(operacao!='S');
	if(varrer!=NULL){
		fim->proximo=NULL;
		varrer=comeco;                                   //Libera a memória quando sai do progarama.
		while(varrer->proximo!=NULL){
			anterior=varrer;
			varrer=varrer->proximo;
			if((varrer->proximo==NULL)&&(varrer!=comeco)){
				free(varrer);
				varrer=comeco;
				anterior->proximo=NULL;
			}
		}
		if(varrer->proximo==NULL){
			free(varrer);	
			varrer=NULL;
			anterior=NULL;
			comeco=NULL;
		}
		if(comeco==NULL){
			anterior=NULL;
			varrer=NULL;
			fim=NULL;
			auxiliar=NULL;
		}
	}else{
		free(auxiliar);
		auxiliar=varrer;
		free(comeco);
		comeco=varrer;
		free(fim);
		fim=varrer;
		free(anterior);
		anterior=varrer;
		}
	return 0;
}

