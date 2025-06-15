#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int op, valor, cresceu;
    arvore a = NULL;
    while(1) {
        scanf("%d", &op);
        switch(op) {
            case 1:
                scanf("%d", &valor);
                a = inserir(a, valor, &cresceu);
                break;
            case 2:
                preorder(a);
                printf("\n");
                break;
            case 99:
                exit(0);
        }
    }
    return 0;
}