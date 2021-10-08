#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"
#include "avlTree.c"


int main(){
avlTree novaArv;
No *bsc;
create(&novaArv);
inserir(&novaArv, 12);
inserir(&novaArv, 38);
inserir(&novaArv, 50);
preOrdem(novaArv);
is_Empty(novaArv);

bsc = busca(novaArv, 38);
printf("%d\n", bsc->data);
printf("valor a esquerda de %d eh: %d\n", bsc->data, bsc->left->data);
printf("Valor a direita de %d eh: %d\n", bsc->data, bsc->right->data);

novaArv = liberar(novaArv);

if(liberar(novaArv) == NULL){  /*Se for retornado NULL, significa que foi liberada da memória com sucesso*/
    printf("Arvore liberada da memoria\n");
}
posOrdem(novaArv);



return 0;
}