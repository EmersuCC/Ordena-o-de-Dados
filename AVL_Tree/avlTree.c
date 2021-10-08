#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"

void create(avlTree *T){
    *T = NULL;
}

int is_Empty(avlTree T){
    if(T==NULL)
        printf("ARVORE VAZIA\n");
    else
        printf("ARVORE CONTEM NO\n");

}

No *createNode(int valor){
    No *novoNo = malloc(sizeof(No));
    
    if(novoNo == NULL)
        return 0;
    
    novoNo->data = valor;
    novoNo->height = 0;
    novoNo->left = NULL;
    novoNo->right = NULL;   
    return novoNo;
}

avlTree *liberar(avlTree T){  
    if(T == NULL) return 0;

    liberar(T->left);
    liberar(T->right);

    free(T);

    T = NULL;

    return T;    
}

int altura_No(No *T){  /*RETORNA A ALTURA DO NO*/
    if(T == NULL){
        return -1;
    }else{
        return T->height;
    }
}

No *busca(No *T, int valor){  /*Busca um nó e retorna um ponteiro para o mesmo*/
    if(T == NULL){
        return NULL;
    }

    if(T->data == valor)
        return T;

    if(T->data > valor)
        return busca(T->left, valor);

    else
        return busca(T->right, valor);
}

int maior(int a, int b){
    return a > b ? a : b;  /*Calcula o maior valor entre dois inteiros, será usado para calcular qual a maior subarvore*/
}

int balanceamento_F(No *T){
    return labs(altura_No(T->left) - altura_No(T->right));  /*Calcula o fator balanceamento atráves das subarvores*/
}

void rotacao_LL(avlTree *T){ /*Rotação para esquerda*/
    No *auxNo;
    auxNo = (*T)->left;  /*No auxiliar aponta para a esquerda do No T*/
    (*T)->left = auxNo ->right; /*No esquerdo de T, passa a apontar para a sua direita*/
    auxNo->right = (*T); /*No esquerdo troca de logar com direito*/
    (*T)->height = maior(altura_No((*T)->left), altura_No((*T)->right)) + 1;  /*Regula a altura da árvore*/
    
    auxNo->height = maior(altura_No(auxNo->left), ((*T)->height)) + 1 ;
    (*T) = auxNo;
}

void rotacao_RR(avlTree *T){  /*Rotação para direita*/
    No *aux;
    aux = (*T)->right; /*Ponteiro auxiliar para o nó direito ta raiz*/
    (*T)->right = aux->left; /*Ponteiro direito passa a pontar para o nó esquerdo*/
    aux->left = (*T); /*Nó esquerdo troca de lugar com o direito*/
    (*T)->height = maior(altura_No((*T)->left), altura_No((*T)->right)) + 1;  /*Atualiza a altura, pegando o maior valor das subarvores*/
    aux->height = maior(altura_No(aux->right), (*T)->height) + 1;
    (*T) = aux;

}

void rotacao_LR(avlTree *T){  /*Rotação esquerda direita*/
    rotacao_LL(&(*T)->left);
    rotacao_RR(T);
}

void rotacao_RL(avlTree *T){  /*Rotação direita esquerda*/
    rotacao_RR(&(*T)->right);
    rotacao_LL(T);
}

No *valorMin(No *T){
    No *aux, *aux2;
    aux = T;
    aux2 = T->left;
    while(aux2 != NULL){
        aux = aux2;
        aux2 = aux2->left;
    }
    return aux;
}


int inserir(avlTree *T, int valor){
    int ok;
    if(*T == NULL){
        *T = createNode(valor);
        return 1;
    }

    No *aux = *T;
    if(valor < aux->data){
        ok = inserir(&(aux->left), valor); /*Variável auxiliar para verificar se o valor foi inserido*/
        if(ok == 1){
            if(balanceamento_F(aux) >= 2){  /*Caso o valor seja inserido e o balanceamento já esteja no limite*/
                if(valor < (*T)->left->data){ /*Se o valor inserido for menor*/
                    rotacao_LL(T); /*Aplico uma rotação a esquerda para balancear*/
                }else{
                    rotacao_LR(T); /*Se não for. Aplico uma rotação a esquerda e depois a direita para balancear*/
                }
            }
        }
    }else{
        if(valor > aux->data){
            ok = inserir(&(aux->right), valor);
            if(ok == 1){
                if(balanceamento_F(aux) >= 2){
                    if((*T)->right->data < valor){ /*Já se o valor for maior*/
                        rotacao_RR(T);  /*Aplico rotação a direita*/
                    }else{
                        rotacao_RL(T);  /*Se não, aplico uma rotação a direita, e depois a esquerda*/
                    }
                }
            }
        }else{
            printf("Já existe esse valor\n");
            return 0;
        }
    }

        aux->height = maior(altura_No(aux->left), altura_No(aux->right)) + 1; /*Ajusta o valor da altura da árvore, pegando o maior valor entre elas*/
        return ok;
}

int delete(avlTree *T, int valor){
    int ok;
    if(*T == NULL)
        return 0;

    if((*T)->data == valor){ /*Se o valor for igual a raiz*/
        if((*T)->left == NULL || (*T)->right == NULL){ /*Se um de seus filhos for nulo*/
            No *aux;
            aux = (*T);
            if((*T)->left != NULL){ /*Se existir um filho a esquerda*/
                *T = (*T)->left; /*Ele será a raiz*/
            }else{
                *T = (*T)->right; /*Se não houver um filho a esquerda mas houver um a direita, este será a nova raiz*/
            }
            free(aux); /*Libera o nó a ser excluido*/
        }else{
            No *temp; /*Se existe filho a esquerda e filho a direita, então..*/
            valorMin((*T)->right); /*Procuro o menor valor na subarvore a direita*/
            (*T)->data = temp->data; /*Guardo o valor da raiz*/
            delete(&(*T)->right, (*T)->data); 
            if(balanceamento_F(*T) >= 2){ 
                if(altura_No((*T)->left->right) <= altura_No((*T)->left->left)){ /*Se a altura da subarvore a direita do filho esquerdo da raiz for maior que a da esquerda..*/
                    rotacao_LL(T); /*Rotaciono para a esquerda*/
                }else{
                    rotacao_LR(T); /*Se nao, rotaciono para a direita*/
                }
            }
        }
        if(*T != NULL){
            (*T)->height = maior(altura_No((*T)->left), altura_No((*T)->right)) + 1;  /*Reajusto a altura da arvore*/
        }

        return 1;
    }


    
    if(valor < (*T)->data){
        ok = delete(&(*T)->left, valor);
        if(ok == 1){
            if(balanceamento_F(*T) >= 2){
                if(altura_No((*T)->right->left) <= altura_No((*T)->right->right)){
                    rotacao_RR(T);
                }else{
                    rotacao_RL(T);
                }
            }

        }
    }
    if(valor > (*T)->data){
        ok = delete((*T)->right, valor);
        if(ok == 1){
            if(balanceamento_F(*T) >= 2){
                if(altura_No((*T)->left->right) <= altura_No((*T)->left->left)){
                    rotacao_LL(T);
                }else{
                    rotacao_LR(T);
                }
            }
        }
    }
    
    (*T)->height = maior(altura_No((*T)->left), altura_No((*T)->right)) + 1 ;
    
    return ok;
}

void preOrdem(avlTree T){
    if(T == NULL)
    return;

    printf("%d\n", T->data);
    
    if(T->left != NULL)
    preOrdem(T->left);

    if(T->right != NULL)
    preOrdem(T->right);
}

void inOrdem(avlTree T){
    
    if(T == NULL)
    return;

    if(T->left != NULL)
    inOrdem(T->left);
    
    printf("%d\n", T->data);

    if(T->right != NULL)
    inOrdem(T->right);


}

void posOrdem(avlTree T){

    if(T == NULL)
    return;

    if(T->left != NULL)
    posOrdem(T->left);

    if(T->right != NULL)
    posOrdem(T->right);

    printf("%d\n", T->data);
}
