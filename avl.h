#ifndef AVL_H
#define AVL_H

typedef struct no {
    int valor;
    int fb;
    struct no *esq, *dir;
} no;

typedef struct no* arvore;

arvore rotacao(arvore pivo);
arvore rotacaoSimplesEsquerda(arvore pivo);
arvore rotacaoDuplaEsquerda(arvore pivo);
arvore rotacaoSimplesDireita(arvore pivo);
arvore rotacaoDuplaDireita(arvore pivo);
int maiorElemento (arvore pivo);
arvore remover(arvore raiz, int valor);
arvore inserir (arvore raiz, int valor, int *cresceu);
void preorder(arvore raiz);

#endif