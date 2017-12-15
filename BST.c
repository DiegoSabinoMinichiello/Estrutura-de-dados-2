#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
	int chave;
	struct Arv *dir, *esq;
}Arv;

Arv *novoNodo(int chave);
void inserir(Arv **arvprin);
void preOr(Arv *bst);
void inOr(Arv *bst);
void postOr(Arv *bst);
void buscmin(Arv *subt, Arv **aux);
void busc(Arv *bst,int chave, Arv **aux);
Arv *deletar(Arv *bst, int chave);
void printMenu();

int main(){
	Arv *arvprin=NULL;
	Arv *aux=NULL;
	int menu;

	do {		
		printMenu();
		scanf("%d",&menu );
		aux=NULL;
		switch (menu) {
			case 1:
				inserir(&arvprin);
				break;
			case 2:
				if(arvprin==NULL)
					printf("\nNao tem nada aqui!\n");
				else{
					printf("------------------------\n");
					printf("\nDigite o nodo que vai ser deletado\n-> ");
					int del;
					scanf("%d",&del);
					deletar(arvprin,del);
				}
				break;

			case 3:
				printf("------------------------\n");
				printf("Digite o número para buscar\n-> ");
				int buscar;
				scanf("%d",&buscar );
				busc(arvprin,buscar,&aux);
				if(aux==NULL)
					printf("Número não esta arvore\n");
				break;

			case 4:
				if(arvprin==NULL)
					printf("\nNao tem nada aqui!\n");
				else
					preOr(arvprin);
				break;
			case 5:
				if(arvprin==NULL)
					printf("\nNao tem nada aqui!\n");
				else
			 		inOr(arvprin);
				break;
			case 6:
				if(arvprin==NULL)
					printf("\nNao tem nada aqui!\n");
				else
				postOr(arvprin);
				break;
			default:
				break;

		}
	} while(menu!=0);

	return 0;
}

Arv *novoNodo(int chave){
	Arv *novo = malloc(sizeof(Arv));
	novo->chave=chave;
	novo->dir=NULL;
	novo->esq=NULL;
	return novo;
}

void inserir(Arv **arvprin){
	int chave;
	printf("------------------------\n");
	printf("\nDigite o número que você quer inserir\n-> ");
	scanf("%d", &chave);
	if(*arvprin==NULL){
		*arvprin=novoNodo(chave);
	}else{
		Arv *ins=malloc(sizeof(Arv));
		for(ins=*arvprin;ins!=NULL;){
			if(ins->chave>=chave){
				if(ins->esq!=NULL)
					ins=ins->esq;
				else{
					ins->esq=novoNodo(chave);
					break;
				}
			}else{
				if(ins->dir!=NULL)
					ins=ins->dir;
				else{
					ins->dir=novoNodo(chave);
					break;
				}
			}
		}
	}
}

void preOr(Arv *bst){
	if(bst==NULL)
		return;
	printf("------------------------\n");
	printf("%d\n",bst->chave);
	preOr(bst->esq);
	preOr(bst->dir);
}

void inOr(Arv *bst){
	if(bst==NULL)
		return;

	inOr(bst->esq);
	printf("------------------------\n");
	printf("%d\n",bst->chave);
	inOr(bst->dir);
}

void postOr(Arv *bst){
	if(bst==NULL)
		return;
	postOr(bst->esq);
	postOr(bst->dir);
	printf("------------------------\n");
	printf("%d\n",bst->chave);
}

void buscmin(Arv *subt, Arv **aux){
	Arv *auxbusc=*aux;
	if(subt!=NULL){
		if(auxbusc->chave > subt->chave){
			*aux=subt;
			return;
		}
		buscmin(subt->esq,aux);
		buscmin(subt->dir,aux);
	}
}
void busc(Arv *bst,int chave, Arv **aux){
	if(bst!=NULL){
		if(bst->chave==chave){
			*aux=bst;
			printf("------------------------\n");
			printf("O nodo com o número %d esta na arvore e seu endereço é %d\n", bst->chave, bst->chave);
			return;
		}
		busc(bst->esq,chave,aux);
		busc(bst->dir,chave,aux);
	}
}


Arv *deletar(Arv *bst, int chave){
	if(bst==NULL)
		return bst;
	else if(bst->chave>chave)
		bst->esq=deletar(bst->esq,chave);
	else if(bst->chave<chave)
		bst->dir=deletar(bst->dir,chave);
	else{
			if(bst->esq == NULL && bst->dir==NULL){
				free(bst);
				bst=NULL;
			}else if(bst->esq==NULL){
				Arv *aux=bst;
				bst=bst->dir;
				free(aux);
			}else{
				Arv *aux=bst->dir;
				buscmin(bst->dir, &aux);
				bst->chave=aux->chave;
				bst->dir=deletar(bst->dir,aux->chave);
			}
	}
	return bst;
}

void printMenu(){
	printf("------------------------\n");
	printf("1 Inserir nodo na Árvore\n");
	printf("2 Deletar nodo da Árvore\n");
	printf("3 Buscar\n");
	printf("4 PreOrder\n");
	printf("5 InOrder\n");
	printf("6 PostOrder\n");
	printf("0 Sair\n");
	printf("------------------------\n");
	printf("-> ");
}