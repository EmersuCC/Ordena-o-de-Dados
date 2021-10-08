#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

typedef struct No {
    int data;
    int height;
    struct No *left;
    struct No *right;
}No;

typedef struct No *avlTree; /*Ponteiro para raiz da árvore*/

void create(avlTree *T); /*Cria a árvore*/
int is_Empty(avlTree T); /*Verifica se a árvore ta vazia*/
No *createNode(int valor); /*Cria e define um nó*/
avlTree *liberar(avlTree T); /*Limpa a árvore da memória*/
int altura_No(No *T); /*Retorna a altura do nó*/
No *busca(No *T, int valor); /*Busca um nó na árvore*/
int maior(int a, int b); /*Retorna o maior entre dois ints*/
int balanceamento_F(No *T); /*retorna o fator balancemanto*/
void rotacao_LL(avlTree *T); /*Rotaciona para a esquerda*/
void rotacao_RR(avlTree *T); /*Rotaciona para direita*/
void rotacao_LR(avlTree *T); /*Rotaciona para a esquerda e depois para a direita*/
void rotacao_RL(avlTree *T); /*Rotaciona para a direita e depois para a esquerda*/
No *valorMin(No *T);  /*Retorna o valor min da árvore*/
int inserir(avlTree *T, int valor); /*Insere um no na arvore*/
int delete(avlTree *T, int valor); /*Deleta um nó da árvore*/
void preOrdem(avlTree T); /*printa em preOrdem*/
void inOrdem(avlTree T); /*Printa emOrdem*/
void posOrdem(avlTree T); /*Printa em posOrdem*/

#endif


