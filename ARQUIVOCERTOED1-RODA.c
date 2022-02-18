
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Aluno{
	char Matricula[10];
	char Nome[15], Sobrenome[10];
	float nota1, nota2;
	char Historico[4];
	void *proximo;
};

typedef struct Aluno Alunos;
Alunos Turma; 
long int t = sizeof(Turma);
struct Alunos1{
	char Matricula[10];
	char Nome[15], Sobrenome[15];
	float Media;
	void *proximo;
};
typedef struct Alunos1 Turma1;
Turma1 *Comeco,*Final,*Troca,*Anterior,*Varrer;
FILE *ArquivoTurma;

void inserirarq(int turma){
	char excluir[2],R='S';
	excluir[0]='@';
	Comeco=NULL;
	fseek(ArquivoTurma,0,0);
	do {
		system("cls");
		printf("\n\n\n*** Ranking ***\n\n\n");
		Varrer=Comeco;
		while(Varrer!=NULL){
			if(strcmp(Varrer->Nome,excluir)!=0){
				printf("\n");
				printf("%s - ",Varrer->Matricula);
				printf("%s ",Varrer->Nome);
				printf("%s - ",Varrer->Sobrenome);
				printf("%.1f",Varrer->Media);
				printf("\n");
			}
			Varrer=Varrer->proximo;
		}
		Troca=(Turma1 *) malloc(sizeof(Turma1));  
		fseek(ArquivoTurma,0,0);
		printf("Matricula: ");
		scanf("%s",Turma.Matricula);
		printf("Nome e sobrenome: ");
		scanf("%s",Turma.Nome);
		scanf("%s",Turma.Sobrenome);
		printf("Nota da primeira avaliacao: ");
		scanf("%f",&Turma.nota1);
		printf("Nota da segunda avaliacao: ");
		scanf("%f",&Turma.nota2);
		printf("Historico: ");
		scanf("%s",Turma.Historico);
		strcpy(Troca->Matricula,Turma.Matricula);
		strcpy(Troca->Sobrenome,Turma.Sobrenome);
		strcpy(Troca->Nome,Turma.Nome);
		Troca->Media=(Turma.nota1+Turma.nota2)/2;
		Troca->proximo=NULL;
		if(Comeco==NULL){ 
			Troca->proximo=NULL;
			Comeco=Troca;
			Final=Troca;
		}else if(Troca->Media>=Comeco->Media){
			Troca->proximo=Comeco;
			Comeco=Troca;
		}else if(Troca->Media<=Final->Media){
			Final->proximo=Troca;
			Final=Troca;
		}else{
			Varrer=Comeco->proximo;
			Anterior=Comeco;
			while(Troca->Media<Varrer->Media){
				Anterior=Varrer;
				Varrer=Varrer->proximo;
			}
			Anterior->proximo=Troca;
			Troca->proximo=Varrer;
		}
		system("cls");
		printf("\n\n\n*** Ranking ***\n\n\n");
		printf("--- Turma: %d ---",turma);
		Varrer=Comeco;
		while(Varrer!=NULL){
			if(strcmp(Varrer->Nome,excluir)!=0){
				printf("\n\n");
				printf("%s - ",Varrer->Matricula);
				printf("%s ",Varrer->Nome);
				printf("%s - ",Varrer->Sobrenome);
				printf("%.1f",Varrer->Media);
				printf("\n");
			}
			Varrer=Varrer->proximo;
		}
		fseek(ArquivoTurma,0,2);
		fwrite(&Turma,t,1,ArquivoTurma);
		printf("\nNova inclusao? S/N ");
		scanf(" %c",&R);
		R=toupper(R);
	}while (R!='N');
}

void Incluir(int turma) {
	char R,excluir[2];
	int Achou=0;
	fclose(ArquivoTurma);
	ArquivoTurma=fopen("Turma.dat","a+b");
	excluir[0]='@';
	do{
		do {
			fread(&Turma,t,1,ArquivoTurma);
			if(strcmp(Turma.Matricula,excluir)==0){
			    Achou=1;
				system("cls");
				printf("*** Incluir ***\n\n");
				printf("Matricula: ");
				scanf("%s",Turma.Matricula);
				printf("Nome e sobrenome: ");
				scanf("%s",Turma.Nome);
				scanf("%s",Turma.Sobrenome);
				printf("Nota da primeira avaliacao: ");
				scanf("%f",&Turma.nota1);
				printf("Nota da segunda avaliacao: ");
				scanf("%f",&Turma.nota2);
				printf("Historico: ");
				scanf("%s",Turma.Historico);
				fseek(ArquivoTurma,0,2);
				fwrite(&Turma,t,1,ArquivoTurma);
			}else{
				system("cls");
				printf("*** Incluir ***\n\n");
				printf("Matricula: ");
				scanf("%s",Turma.Matricula);
				printf("Nome e sobrenome: ");
				scanf("%s",Turma.Nome);
				scanf("%s",Turma.Sobrenome);
				printf("Nota da primeira avaliacao: ");
				scanf("%f",&Turma.nota1);
				printf("Nota da segunda avaliacao: ");
				scanf("%f",&Turma.nota2);
				printf("Historico: ");
				scanf("%s",Turma.Historico);
				fseek(ArquivoTurma,0,2);
				fwrite(&Turma,t,1,ArquivoTurma);
			}
		}while (!feof(ArquivoTurma)&&(Achou==1));
		printf("\nNova inclusao? S/N ");
		scanf(" %c",&R);
		R=toupper(R);
		}while (R!='N');
	fclose(ArquivoTurma);
	//inserirarq(turma);
	system("pause"); 
	return;
	
}

long int TamanhoArquivo(){
	fseek(ArquivoTurma,0,2);
	long int R=ftell(ArquivoTurma)/t;
	return R;
}	

void Excluir(int turma){
	system("cls");
	printf("\n\n\n*** Excluir ***\n\n\n");
	char mat[10],excluir[2];
	excluir[0]='@';
	fclose(ArquivoTurma);
	ArquivoTurma=fopen("Turma.dat","r+b");
	int c=0,cont=0;
	fseek(ArquivoTurma,0,0);
	printf("Digite a matricula do aluno que deseja excluir: ");
	scanf("%s",mat);
	Varrer=Comeco;
		while(cont==0){
			if((strcmp(Varrer->Matricula,mat)==0)){//&&(strcmp(Varrer->Sobrenome,Sobrenome)==0)){
				strcpy(Varrer->Nome,excluir);
				strcpy(Varrer->Sobrenome,excluir);
				strcpy(Varrer->Matricula,excluir);
				printf("\nDado excluido do ranking!\n");
				c++;
				cont=1;
			}
 			Varrer=Varrer->proximo;
		    if(Varrer==Comeco){
				cont++;
			}
		}
		
	cont=0;	
		
	if (TamanhoArquivo()!=0){
		do {
			fread(&Turma,t,1,ArquivoTurma);
			if (strcmp(Turma.Matricula,mat)==0){
				cont=1;
				c++;
				printf("Matricula: %s\n",Turma.Matricula);	
				printf("Nome: %s\n",Turma.Nome);
				printf("Sobrenome: %s\n",Turma.Sobrenome);
				printf("Media: %.2f\n",(Turma.nota1+Turma.nota2)/2);
				printf("Historico: %s\n",Turma.Historico);
			}
		}while (!feof(ArquivoTurma)&&(cont==0));
		if (cont==0){
			printf("Registro inexistente!"); 
		}else{
			printf("Digite @: \n"); 
			scanf("%s",Turma.Matricula);
			printf("Digite @: \n"); 
			scanf("%s",Turma.Nome);
						printf("Digite @: \n"); 
			scanf("%s",Turma.Sobrenome);
			fseek(ArquivoTurma,-t,1);
			fwrite(&Turma,t,1,ArquivoTurma);
			printf(">>> Exclusao efetuada com sucesso! <<<\n");
		}
		fclose(ArquivoTurma);
	}else{
		printf("Arquivo Vazio.  Nao existem dados a excluir.");
		system("pause");
	}	
		if(c!=2){
			printf("Esta pessoa nao esta na lista.\n");
		}
		
	system("pause");	
		//inserirarq(turma);
}

void Alterar(int turma){
	fclose(ArquivoTurma);
	ArquivoTurma=fopen("Turma.dat","r+b");
	if (TamanhoArquivo()!=0){
		system("cls");
		printf("*** Alterar ***\n\n");  
		fseek(ArquivoTurma,0,0);
		printf("Qual aluno (Matricula)? ");
		char Matricula[10];
		scanf("%s",Matricula);
		int Achou=0;
		do {
			fread(&Turma,t,1,ArquivoTurma);
			if (strcmp(Turma.Matricula,Matricula)==0){
				Achou=1;
				printf("Matricula: %s\n",Turma.Matricula);	
				printf("Nome: %s\n",Turma.Nome);
				printf("Sobrenome: %s\n",Turma.Sobrenome);
				printf("Media: %.2f\n",(Turma.nota1+Turma.nota2)/2);
				printf("Historico: %s\n",Turma.Historico);
			}
		}while (!feof(ArquivoTurma)&&(Achou==0));
		if (Achou==0){
			printf("Registro inexistente!"); 
		}else{
			printf("Qual a nova nota da primeira avalicao? \n"); 
			scanf("%f",&Turma.nota1);
			printf("Qual a nova nota da segunda avalicao? \n"); 
			scanf("%f",&Turma.nota2);
			printf("Qual o novo historico? \n");
			scanf("%s",Turma.Historico);
			fseek(ArquivoTurma,-t,1);
			fwrite(&Turma,t,1,ArquivoTurma);
			printf(">>> Alteracao efetuada com sucesso! <<<\n");
		}
		system("pause");
		fclose(ArquivoTurma);
		//ArquivoTurma=fopen("Turma.dat","a+b");
	}else{
		printf("Arquivo Vazio.  Nao existem dados a alterar.");
		system("pause");
	}
	//inserirarq(turma);
	return;
}

void Consultar() {
	system("cls");
	printf("*** Consultar ***\n\n");  
	fclose(ArquivoTurma);
	ArquivoTurma=fopen("Turma.dat","r+b");
	fseek(ArquivoTurma,0,0);
	printf("Qual aluno (Matricula)? ");
	char Matricula[10];
	scanf("%s",Matricula);
	int Achou=0;
	do {
		fread(&Turma,t,1,ArquivoTurma);
		if (strcmp(Turma.Matricula,Matricula)==0){
		Achou=1;	
		printf("Nome: %s\n",Turma.Nome);
		printf("Sobrenome: %s\n",Turma.Sobrenome);
		printf("Media: %.2f\n",(Turma.nota1+Turma.nota2)/2);
		printf("Historico: %s\n",Turma.Historico);
		}
	}while (!feof(ArquivoTurma)&&(Achou==0));	
	if (Achou==0){
		printf("Registro inexistente!");  
	}
	fclose(ArquivoTurma);
	system("pause");
	return;
}

void Listar() {
	char excluir[2];
	excluir[0]='@';
	system("cls");
	printf("*** Listar todos ***\n\n");
	fclose(ArquivoTurma);
	ArquivoTurma=fopen("Turma.dat","a+b");  
	fseek(ArquivoTurma,0,0);
	do {
		fread(&Turma,t,1,ArquivoTurma);
		if (!feof(ArquivoTurma)){
			if(strcmp(Turma.Nome,excluir)!=0){
				printf("Nome: %s\n",Turma.Nome);
				printf("Sobrenome: %s\n",Turma.Sobrenome);
				printf("Media: %.2f\n",(Turma.nota1+Turma.nota2)/2);
				printf("Historico: %s\n",Turma.Historico);
				printf("Matricula: %s\n",Turma.Matricula);			
				printf("\n\n");
		
			}
		}
	}while (!feof(ArquivoTurma));
	
	fclose(ArquivoTurma);
	system("pause");
	return;
}

int main(int argc, char **argv)
{
	ArquivoTurma=fopen("Turma.dat","a+b");
	int turma;
	printf("\n\n\n*** Ranking ***\n\n\n");
	printf("Digite a Turma: ");
	do{
		scanf("%d",&turma);
		if(turma<0){
			printf("\nTurma invalida, digite novamente a turma: ");
		}
	}while(turma<0);
	//inserirarq(turma);
	char opcoes;
	do{
		system("cls");
		printf("\n\n\n*** Arquivo ***\n\n\n");
		printf("\nQual operacao deseja efetuar?\n");
		printf("\nI-Inserir");
		printf("\nA-Alterar");
		printf("\nC-Consultar");
		printf("\nL-Listar");
		printf("\nE-Excluir");
		printf("\nS-Sair\n\n");
		scanf(" %c",&opcoes);
		opcoes=toupper(opcoes);
		switch (opcoes){
			case 'I': Incluir(turma);
					  break;
			case 'A': Alterar(turma); 
			          break;
			case 'C': Consultar(); 
		           	  break;
			case 'L': Listar();
			 		  break;
			case 'E': Excluir(turma);
			 		  break;
		}
	}while(opcoes!='S');
	fclose(ArquivoTurma);
	return 0;
}

