
#include <stdio.h>                                   //Importa as bibliotecas para o uso das funções
#include <stdlib.h>                                  //usadas no programa.
#include <ctype.h> 
#include <string.h>
int main(int argc, char **argv)                      //Início do programa.
{
	struct Alunos{                                   //Criação do registro.
		int Matricula;
		char Nome[50], Sobrenome[20];
		float nota1, nota2;
		void *proximo;
	};
	typedef struct Alunos Turma;                     //Declaração do tipo turma.
	Turma *Comeco,*Final,*Troca,*Anterior,*Varrer;   //Declaração das variáveis tipo ponteiro.
	int Matricula,turma,verificar;                   //Declaração das demais variáveis.
	char Nome[20], Sobrenome[20];
	float nota1, nota2, media;
	char r;                                          //Resposta para continuar inserindo dados.
	r='S';
	verificar=0;
	Comeco=NULL;                                     //Marca o início da estrutura.
	printf("\n\n\n*** Ranking ***\n\n\n");
	printf("Digite a Turma: ");                      //Inserção de dados.
	do{
		scanf("%d",&turma);
		if(turma<0){
			printf("\nTurma invalida, digite novamente a turma: ");
		}
	}while(turma<0);
	while(r=='S'){
		//system("cls");
		system("clear");                             //Limpa a tela.
		printf("\n\n\n*** Ranking ***\n\n\n");
		printf("Digite os dados do aluno:\n");
		Varrer=Comeco;
		while(Varrer!=NULL){                         //Varre a estrutura e mostra dados anteriores
			printf("\n");                            //se houverem.
			printf("%d - ",Varrer->Matricula);
			printf("%s ",Varrer->Nome);
			printf("%s - ",Varrer->Sobrenome);
			printf("%.1f",(Varrer->nota1+Varrer->nota2)/2);
			printf("\n");
			Varrer=Varrer->proximo;
		}
		Troca=(Turma *) malloc(sizeof(Turma));       //Aloca o espaço para a nova variável dinâmica.
		printf("\nMatricula: ");
		do{
			scanf("%d",&Matricula);
			if(Matricula<0){
				printf("\nMatricula invalida, digite novamente a matricula: ");
			}
		}while(Matricula<0);
		printf("\nNome e ultimo sobrenome: ");
		scanf("%s",Nome);
		scanf("%s",Sobrenome);
		Varrer=Comeco;
		while(Varrer!=NULL){                         //Valida os dados, para que não haja ambiguidade (strcmp compara strings).
			if((Matricula==Varrer->Matricula)&&((strcmp(Varrer->Nome,Nome)!=0)||(strcmp(Varrer->Sobrenome,Sobrenome)!=0))){
				Matricula=0;
				printf("\nMatricula invalida, digite novamente a matricula: ");
				do{
					scanf("%d",&Matricula);
					if(Matricula<0){
						printf("\nMatricula invalida, digite novamente a matricula: ");
					}
				}while(Matricula<0);
				if(verificar!=0){                    //Verifica se há alguém com a mesma matrícula, nome e/ou sobrenome diferente.
					printf("\nDigite novamente nome e ultimo sobrenome: ");
					scanf("%s",Nome);
					scanf("%s",Sobrenome);
					verificar=1;
				}
			}else if((Matricula==Varrer->Matricula)&&(strcmp(Varrer->Nome,Nome)==0)&&(strcmp(Varrer->Sobrenome,Sobrenome)==0)){
				Matricula=0;
				printf("\nMatricula invalida, digite novamente a matricula: ");
				do{
					scanf("%d",&Matricula);
					if(Matricula<0){
						printf("\nMatricula invalida, digite novamente a matricula: ");
					}
				}while(Matricula<0);
				printf("\nDigite novamente nome e ultimo sobrenome: ");
				scanf("%s",Nome);
				scanf("%s",Sobrenome);
				verificar=1;
			}else if((Matricula!=Varrer->Matricula)&&((strcmp(Varrer->Nome,Nome)==0)&&(strcmp(Varrer->Sobrenome,Sobrenome)==0))){
				Matricula=0;
				printf("\nMatricula invalida, digite novamente a matricula: ");
				do{
					scanf("%d",&Matricula);
					if(Matricula<0){
						printf("\nMatricula invalida, digite novamente a matricula: ");
					}
				}while(Matricula<0);
				printf("\nDigite novamente nome e ultimo sobrenome: ");
				scanf("%s",Nome);
				scanf("%s",Sobrenome);
				verificar=1;
			}
			Varrer=Varrer->proximo;
		}
		Troca->Matricula=Matricula;                  //Copia os dados para a nova variável.
		strcpy(Troca->Sobrenome,Sobrenome);          //Copia uma string para outra.
		strcpy(Troca->Nome,Nome);
		printf("\nDigite a nota na primeira avaliacao: ");
		do{
			scanf("%f",&nota1);
			if((nota1<0)||(nota1>10)){
				printf("\nNota invalida, digite novamente a nota: ");
			}
		}while((nota1<0)||(nota1>10));
		printf("\nDigite a nota na segunda avaliacao: ");
		do{
			scanf("%f",&nota2);
			if((nota2<0)||(nota2>10)){
				printf("\nNota invalida, digite novamente a nota: ");
			}
		}while((nota2<0)||(nota2>10));
		Troca->nota1=nota1;
		Troca->nota2=nota2;
		media=(nota1+nota2)/2;
		Troca->proximo=NULL;
		if(Comeco==NULL){                            //Insere a nova variável na estrutura dinâmica 
			Troca->proximo=NULL;                     //na posição correta pela ordem do ranking
			Comeco=Troca;                            //de acordo com a situaçao da estrutura.
			Final=Troca;
		}else if(media>=((Comeco->nota1+Comeco->nota2)/2)){
			Troca->proximo=Comeco;
			Comeco=Troca;
		}else if(media<=((Final->nota1+Final->nota2)/2)){
			Final->proximo=Troca;
			Final=Troca;
		}else{
			Varrer=Comeco->proximo;
			Anterior=Comeco;
			while(media<((Varrer->nota1+Varrer->nota2)/2)){
				Anterior=Varrer;
				Varrer=Varrer->proximo;
			}
			Anterior->proximo=Troca;
			Troca->proximo=Varrer;
		}
		//system("cls");
		system("clear");                             //Limpa a tela novamente.
		printf("\n\n\n*** Ranking ***\n\n\n");       //Mostra o ranking, a turma e os dados dos alunos.
		printf("--- Turma: %d ---",turma);
		Varrer=Comeco;
		while(Varrer!=NULL){
			printf("\n\n");
			printf("%d - ",Varrer->Matricula);
			printf("%s ",Varrer->Nome);
			printf("%s - ",Varrer->Sobrenome);
			printf("%.1f",(Varrer->nota1+Varrer->nota2)/2);
			printf("\n");
			Varrer=Varrer->proximo;
		}
		printf("\nContinuar listando? S/N\n");       //Pergunta se novos dados serão inseridos.
		scanf(" %c",&r);
		r=toupper(r);                                //Torna o caractere maiúsculo.
	}
	Varrer=Comeco;                                   //Libera a memória quando sai do progarama.
	while(Varrer->proximo!=NULL){
		Anterior=Varrer;
		Varrer=Varrer->proximo;
		if((Varrer->proximo==NULL)&&(Varrer!=Comeco)){
			free(Varrer);
			Varrer=Comeco;
			Anterior->proximo=NULL;
		}
	}
	if(Varrer->proximo==NULL){
		free(Varrer);	
		Varrer=NULL;
		Anterior=NULL;
		Comeco=NULL;
	}
	if(Comeco==NULL){
		Anterior=NULL;
		Varrer=NULL;
		Final=NULL;
		Troca=NULL;
	}
	return 0;
}                                                    //Fim do programa.
