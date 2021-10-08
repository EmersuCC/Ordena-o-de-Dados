#include <stdio.h>
#include <stdlib.h>
#include "binarieTree.h"
#include "binarieTree.c"

int main(){
    bTree novaArv;
    Node *bsc;
    
    criaArv(&novaArv);
    
    inserirRaiz(&novaArv, 55);
    inserirValor(novaArv, 72);
    inserirValor(novaArv, 30);
    inserirValor(novaArv, 25);
    inserirValor(novaArv, 80);
    inserirValor(novaArv, 90);
    inserirValor(novaArv, 15);
    inserirValor(novaArv, 40);
    
    novaArv = delete(novaArv, 90);
    
    inOrdem(novaArv);
    
    bsc = busca(novaArv, 30); /*Busca o nó com valor 30 e atribui a bsc*/
    /*Printa o nó e seus filhos esquerdo e direito*/
    printf("o no buscado foi o: %d\n", bsc->data);
    printf("o filho a direita eh: %d\n", bsc->right->data);
    printf("o filho a esquerda eh: %d\n", bsc->left->data);
    

    novaArv = liberar(novaArv);  /*Limpa a árvore da memória*/
    ta_Vazia(novaArv);  /*Verifica se a árvore está vazia*/
   
    return 0;
}