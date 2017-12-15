#include <stdio.h>
#include <stdlib.h>
#include "RN.h"


int main(int argc, char *argv[]){

  int inserir, escolha=1, del, busc;
  RNtree* arv = NULL;

  while(escolha!=0){
  	  printf("----------------------------------------------\n");
      printf(" 1 Inserir\n 2 Deletar\n 3 Buscar\n 4 Desenhar\n 5 PreOrder\n 6 InOrder\n 7 PostOrder\n 0 Sair \n Digite sua escolha\n-> ");
      scanf("%d", &escolha);
      printf("----------------------------------------------\n");

      switch(escolha){
        case 1:
            printf("Digite o número para inserir\n-> ");
            scanf("%d", &inserir);
            printf("----------------------------------------------\n");
            arv= Insere(arv,inserir);
        break;
        case 2:
            printf("Digite o número para deletar\n-> ");
            scanf("%d", &del);
            printf("----------------------------------------------\n");
            arv= Remove(arv,inserir);
        break;
        case 3:
            printf("Digite o número para buscar\n-> ");
            scanf("%d", &busc);
            if(Consulta(busc,arv))
                printf("Nodo encontrado");
            else
                printf("Nodo não encontrado");
            printf("----------------------------------------------\n");
        break;
        case 4:
            Desenha(arv,0);
            printf("----------------------------------------------\n");
        break;
        case 5:
            preOr(arv);
            printf("----------------------------------------------\n");
        break;
        case 6:
            inOr(arv);
            printf("----------------------------------------------\n");
        break;
        case 7:
            preOr(arv);
            printf("----------------------------------------------\n");
        break;
    }
  }
  return 0;
}