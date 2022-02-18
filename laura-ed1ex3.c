#include <stdio.h>                                  
#include <stdlib.h>                                 
#include <ctype.h> 
#include <string.h>


struct tAluno {
	char Matricula[10];
	char Nome[15], Sobrenome[15];
	float nota1, nota2;
};

typedef struct tAluno Aluno;

Aluno Alunos; 

FILE *ArquivAluno;

long int t= sizeof(Alunos);


void Incluir() {
  char R;
  do{
    system("clear");
    printf("*** inclusao ***\n\n");
    printf("Matricula: ");
    scanf("%s",Alunos.Matricula);
    printf("\n Nome: ");
    scanf("%s",Alunos.Nome);
    printf("\n Sobrenome: ");
    scanf("%s", Alunos.Sobrenome);
    printf("\n Nota 1 ");
    scanf("%f",&Alunos.nota1);
    printf("\n Nota 2 ");
    scanf("%f",&Alunos.nota2);
    fseek(ArquivAluno,0,2);
    fwrite(&Alunos,t,1,ArquivAluno);
    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);}
  while (R!='N');
  return;}


void Excluir(){
}


void Alterar(){}


void Consultar(){}


void LTodos() {
  system("clear");
  printf("*** lista todos ***\n\n");  
  fseek(ArquivAluno,0,0);
  do {
	fread(&Alunos,t,1,ArquivAluno);
	if (!feof(ArquivAluno)){
	  printf("MAtricula: %s\n",Alunos.Matricula);
      printf("Nome: %s\n",Alunos.Nome);
      printf("Sobrenome: %s\n",Alunos.Sobrenome);
      printf("nota 1: %f\n",Alunos.nota1);
      printf("nota 2: %f\n",Alunos.nota2);

      printf("***\n\n");}}
    while (!feof(ArquivAluno));
 
  return;}


int main(){
  ArquivAluno=fopen("RegAluno.dat","a+b");
  char Opcao;
  do{
	system("clear");
    printf("\n\n> > > Arquivo < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Exluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break;
      case 'E': Excluir(); break;
      case 'A': Alterar(); break;
      case 'C': Consultar(); break;
      case 'T': LTodos(); break;}}
  while (Opcao != 'S');
  fclose(ArquivAluno);
  return 0;
  }
  
