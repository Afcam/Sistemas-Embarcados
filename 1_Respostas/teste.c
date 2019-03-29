#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  char nome[255];
  int idade;

  printf("Digite seu nome: ");
  scanf("%255[^\n]s",nome);
  printf("DIgite sua idade: ");
  scanf("%d",&idade);

  FILE *fp = fopen(strcat(nome,".txt"),"wb");

  if(!fp)
    printf("Erro ao abrir o arquivo");
  else
    fprintf(fp, "Nome: %s\nIdade: %d anos",nome,idade  );

  return 0;
}
