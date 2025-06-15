#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

arvore rotacao(arvore pivo) {
    if(pivo->fb > 0) {
        arvore u = pivo->dir;
        if(u->fb >= 0) return rotacaoSimplesEsquerda(pivo);
        else return rotacaoDuplaEsquerda(pivo);
    } else {
        arvore u = pivo->esq;
        if(u->fb <= 0) return rotacaoSimplesDireita(pivo);
        else return rotacaoDuplaDireita(pivo);
    }
}

arvore rotacaoSimplesEsquerda(arvore pivo) {
    arvore u, t1, t2, t3;
    u = pivo->dir;
    t1 = pivo->esq;
    t2 = u->esq;
    t3 = u->dir;
    u->esq = pivo;
    pivo->dir = t2;

    if(u->fb == 1) {
        pivo->fb = 0;
        u->fb = 0;
    } else {
        pivo->fb = 1;
        u->fb = -1;
    }
    return u;
}

arvore rotacaoDuplaEsquerda(arvore pivo) {
    arvore u, v;
    u = pivo->dir;
    if(u == NULL) return pivo;
    v = u->esq;
    if(v == NULL) return pivo;
    u->esq = v->dir;
    pivo->dir = v->esq;
    v->dir = u;
    v->esq = pivo;

    switch(v->fb) {
        case -1:
            pivo->fb = 0;
            u->fb = 1;
            break;
        case 0:
            pivo->fb = 0;
            u->fb = 0;
            break;
        case 1:
            pivo->fb = -1;
            u->fb = 0;
            break;
    }
    v->fb = 0;
    return v;
}

arvore rotacaoSimplesDireita(arvore pivo) {
    arvore u, t1, t2, t3;
    u = pivo->esq;
    t1 = u->esq;
    t2 = u->dir; 
    t3 = pivo->dir;
    u->dir = pivo;
    pivo->esq = t2;

    if(u->fb == -1) {
        pivo->fb = 0;
        u->fb = 0;
    } else {
        pivo->fb = -1;
        u->fb = 1;
    }
    return u;
}

arvore rotacaoDuplaDireita(arvore pivo) {
    arvore u, v;
    u = pivo->esq;
    if(u == NULL) return pivo;
    v = u->dir;
    if(v == NULL) return pivo;
    u->dir = v->esq;
    pivo->esq = v->dir;
    v->esq = u;
    v->dir = pivo;

    switch(v->fb) {
        case -1:
            pivo->fb = 1;
            u->fb = 0;
            break;
        case 0:
            pivo->fb = 0;
            u->fb = 0;
            break;
        case 1:
            pivo->fb = 0;
            u->fb = -1;
            break;
    }
    v->fb = 0;
    return v;
}

arvore inserir (arvore raiz, int valor, int *cresceu) {
    if(raiz == NULL) {
        arvore novoNo = (arvore) malloc (sizeof(no));
        novoNo->valor = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        novoNo->fb = 0;
        *cresceu = 1;
        return novoNo;
    } else if(valor > raiz->valor) {
            raiz->dir = inserir(raiz->dir, valor, cresceu);
            if(*cresceu) {
                switch(raiz->fb) {
                    case -1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                    case 0:
                        raiz->fb = 1;
                        *cresceu = 1;
                        break;
                    case 1:
                        *cresceu = 0;
                        return rotacao(raiz);
                }
            }
        } else if(valor < raiz->valor){
            raiz->esq = inserir(raiz->esq, valor, cresceu);
            if(*cresceu) {
                switch(raiz->fb) {
                    case -1:
                        *cresceu = 0;
                        return rotacao(raiz);
                    case 0:
                        raiz->fb = -1;
                        *cresceu = 1;
                        break;
                    case 1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                }
            }
        } else {
            *cresceu = 0;
        }
        return raiz;
}

void preorder(arvore pivo){
    if(pivo != NULL) {
        printf("[%d | %d]", pivo->valor, pivo->fb);
        preorder(pivo->esq);
        preorder(pivo->dir);
    }
}