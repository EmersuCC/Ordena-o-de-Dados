#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"


void create(tBTree *T){
    *T = NULL;     /*Cria um ponteiro que aponta pra nulo enquanto não houver raiz.*/
}

int empty(tBTree T){
    if(T == NULL){
    printf("A arvore esta vazia\n");
    }
    else{
    printf("A arvore nao esta vazia\n");
    }
    
return 0;
}


tBTree busca(tBTree T, int dado){
    if(T == NULL)
    return NULL;

    if(T->conteudo == dado){
        return T;
    }

    if(T->conteudo > dado){
        return busca(T->left, dado);
    }
    else{
        return busca(T->right, dado);
    }
}

int insertRoot(tBTree *T, int dado){
    No *novoNo;
   
    if(*T != NULL){ /*Se a arvore ja possui uma raiz, encerro*/
    printf("Ja existe uma raiz\n");
    return 0;
    }
    
    novoNo = malloc(sizeof(No)); /*Aloca um espaco na memoria para um No*/
    
    if(novoNo == NULL) return 0; 

    novoNo->conteudo = dado; /*Conteudo do novo no = dado*/
    novoNo->left = NULL; /*Novo no nn possui filho a direita*/
    novoNo->right = NULL; /*Nem a esquerda*/
    *T = novoNo; /*T, que era nulo, passa a apontar para a nova raiz*/

    return 1;
}

int insertRight(tBTree T, int vPai, int vFilho){
    No *p, *f, *novoNo;
    
    p = busca(T, vPai);
    
    if(p == NULL)
    return 0;

    f = busca(T, vFilho);
    
    if(f != NULL) /*Este dado ja existe na arvore*/
    return 0;
        
    if(p->right != NULL)
    return 0; /*Já existe filho a direita do pai*/

    novoNo = malloc(sizeof(No));
        
    if(novoNo == NULL)
    return 0; /*erro de memoria*/

    novoNo->conteudo = vFilho;
    novoNo->left = NULL;
    novoNo->right = NULL;
    p->right = novoNo;
    printf("Novo no inserido a direita de %d, seu valor eh: %d\n", p->conteudo, p->right->conteudo);
    
    return 1;
    
}

int insereEsquerda(tBTree T, int vPai, int vFilho){
  No *p, *f, *novoNo;
  p = busca(T, vPai);
  if(p == NULL)
  return 0; /*Se não existe uma raiz, não há como inserir um */

  f = busca(T, vFilho);
  
  if(f != NULL)
  return 0; /*Already exist*/

  if(p->left != NULL)
  return 0; /**/

  novoNo = malloc(sizeof(No));
  if(novoNo == NULL)
  return 0; /*Error: insuficient memory*/
  
  novoNo->conteudo = vFilho;
  novoNo->left = NULL;
  novoNo->right = NULL; 
  p->left = novoNo;

  printf("Novo no inserido a esquerda do valor %d, seu valor eh: %d\n", p->conteudo, p->left->conteudo);

  return 1;

}

void preOrdem(tBTree T){
    if(T == NULL)
    return;

    printf("%d\n", T->conteudo);
    
    if(T->left != NULL)
    preOrdem(T->left);

    if(T->right != NULL)
    preOrdem(T->right);
}

void inOrdem(tBTree T){
    
    if(T == NULL)
    return;

    if(T->left != NULL)
    inOrdem(T->left);
    
    printf("%d\n", T->conteudo);

    if(T->right != NULL)
    inOrdem(T->right);


}

void posOrdem(tBTree T){

    if(T == NULL)
    return;

    if(T->left != NULL)
    posOrdem(T->left);

    if(T->right != NULL)
    posOrdem(T->right);

    printf("%d\n", T->conteudo);
}


void printaRaiz(tBTree T){
    if(T != NULL)
    printf("A raiz atual da arvore eh: %d\n", T->conteudo);
}



int main(){
   tBTree novaArv;
   No no;
   create(&novaArv);
   empty(novaArv);
   insertRoot(&novaArv, 20);
   printf("AQUI EMERSON %d\n", busca(novaArv, 20));
   printaRaiz(novaArv);
   empty(novaArv);
   printf("BUSCA: %d", busca(novaArv, 15));
   insertRight(novaArv, 20, 25);
   insertRight(novaArv, 25, 30);
   insereEsquerda(novaArv, 20, 55);
   insereEsquerda(novaArv, 55, 12);
   insereEsquerda(novaArv, 25, 46);
   
   insertRoot(&novaArv, 25);
   printf("Printando em PRE-ORDEM\n");
   printf("\n");
   preOrdem(novaArv);
   printf("\n");
   printf("Printando em IN-ORDEM\n");
   printf("\n");
   inOrdem(novaArv);
   printf("\n");
   printf("Printando em POS-ORDEM\n");
   printf("\n");
   posOrdem(novaArv);
   printf("\n");
}