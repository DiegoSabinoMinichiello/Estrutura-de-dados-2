#ifndef RN_H_INCLUDED
#define RN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct RNnodo {
  int key;
  int red; /* se red=0 então o nodo é preto */
  struct RNnodo* esq;
  struct RNnodo* dir;
  struct RNnodo* pai;
};

typedef struct  RNnodo RNtree;

// declarar o nodo NULL
static RNtree* NodoNULL = NULL;

// Definições das Funções
RNtree* RotacaoSimplesEsq(RNtree* t);
RNtree* RotacaoSimplesDir(RNtree* t);
RNtree* VerificaRN(RNtree* t, int key);
RNtree* Insere(RNtree* t, int key);
int Consulta(int X, RNtree* T );
RNtree* Maior(RNtree* t);
RNtree* Menor(RNtree* t);
RNtree* Remove(RNtree* t, int key);
//void Destroi(RNtree* t);
void Desenha(RNtree* t , int nivel);

#endif // RN_H_INCLUDED