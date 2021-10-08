#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"
#include "Stree.c"


int main(){
   No *aux, *aux2; 
   tBTree novaArv; 
   create(&novaArv); /*Cria a árvore*/
   empty(novaArv); /*Verifica se a arvore está vazia*/
   insert(&novaArv, 50);  /* Insere os valores 50, 60, 40, etc*/
   insert(&novaArv, 60);  
   insert(&novaArv, 40);    
   insert(&novaArv, 12);
   insert(&novaArv, 1);
   insert(&novaArv, 75);
   insert(&novaArv, 45);
   insert(&novaArv, 35);
   insert(&novaArv, 55);
   empty(novaArv);
   

   printf("O valor minimo eh: %d\n", valorMin(novaArv));  /*Mostra o menor valor da árvore*/
  
   inOrdem(novaArv);
   printaRaiz(novaArv);

   aux = busca(novaArv, 60); /*Busca um nó na arvore e faz aux apontar pra ele*/
  
   /*Mostra o valor do nó e dos filhos buscados*/
  
   printf("o no buscado foi o: %d\n", aux->conteudo);
   printf("o filho a direita de %d eh: %d\n", aux->conteudo, aux->right->conteudo);
   printf("o filho a esquerda de %d eh: %d\n", aux->conteudo, aux->left->conteudo);

   
   novaArv = delete(novaArv, 50); /*Deleta a raiz 50*/
   printaRaiz(novaArv);
   printf("Valor a direita da raiz: %d\n", novaArv->right->conteudo);

   inOrdem(novaArv); 
   
   
   novaArv = liberar(novaArv);  /*Libera a árvore*/

   empty(novaArv); /*Verifica se realmente está vazio*/
  
   return 0;
}