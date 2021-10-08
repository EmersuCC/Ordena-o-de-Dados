#ifndef SEARCHTREE_H_INCLUDED
#define SEARCHTREE_H_INCLUDED

typedef struct No
{
    int conteudo; /*Conteudo do no*/
    struct No *left; /*Filho a esquerda*/
    struct No *right; /*Filho a direita*/
    
}No; /* Tipo No*/ 

typedef struct No *tBTree; /*ponteiro para raiz da árvore*/

void create (tBTree *T); /*Cria a árvore*/
No *createNode(int data); /*Cria um nó*/
void empty(tBTree T); /*Verifica se a árvore está vazia*/
No *busca(No *T, int dado); /*busca um nó na arvore com o valor citado*/
int valorMin(tBTree T); /*Retorna o manor valor da arvore*/
int insert(tBTree *T, int dado); /*Insere valores na arvore*/
int delete(No *T, int valor); /*deleta um nó da arvore*/
tBTree *liberar(tBTree); /*Libera a árvore da memória*/
void printaRaiz(tBTree T); /*Printa a atual raiz da árvore*/
void PreOrdem(tBTree T); /*Printa em preOrdem*/
void InOrdem(tBTree T); /* Printa em ordem*/ 
void PosOrdem(tBTree T); /*printa em pos ORdem*/

#endif 
