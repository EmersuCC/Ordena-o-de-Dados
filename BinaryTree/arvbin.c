
#include <stdio.h>
#include <stdlib.h>

#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED

typedef struct no {
	int conteudo;  	 /* conteudo */
	struct  no *esq; /* ref. para filho da esquerda */
	struct  no *dir; /* ref. para filho da direita  */
} tNo;       /* tipo do n� */

typedef tNo *tArvBin; /* tipo �rvore bin�ria */

void cria (tArvBin *T);
int vazia (tArvBin T);
tArvBin busca(tArvBin T, int dado);
int insereRaiz(tArvBin *T, int dado );
int insereDireita(tArvBin T, int vPai, int vFilho );
int insereEsq(tArvBin T, int vPai, int vFilho );

void exibePreOrdem(tArvBin T);
void exibeInOrdem(tArvBin T);
void exibePosOrdem(tArvBin T);

#endif // ARVBIN_H_INCLUDED

/**Cria uma �rvore vazia */
void cria (tArvBin *T) {
	*T = NULL;
}

/**Verifica se a �rvore est� vazia*/
int vazia (tArvBin T) {
    if (T == NULL)
        return 1;
    else
        return 0;
}

/**Buscar um elemento na �rvore
    Retorna o endere�o se o elemento for
    encontrado, caso contr�rio retorna NULL*/
tArvBin busca(tArvBin T, int dado) {
	tArvBin achou;
	if (T == NULL)
		return NULL;  /* Arvore Vazia*/

	if(T->conteudo == dado)
		return T; /*Elem. encontrado na raiz*/

	achou = busca(T->esq, dado); /* Tenta na sub-arv da esq */
	if (achou == NULL)
		achou = busca(T->dir, dado); /* Tenta na sub-arv da dir */

	return achou;
}

/** Insere um n� raiz em uma �rvore vazia
    Retorna 1 se a inser��o for com sucesso.
    Caso contr�rio 0 */
int insereRaiz(tArvBin *T, int dado ) {
	tNo *novoNo;
	if (*T != NULL)
		return 0;  /*Erro: �rvore n�o est� vazia*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
        return 0;  /*Err: mem.  Insuf. */

	novoNo->conteudo = dado;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	*T = novoNo;
	return 1;
}

/** Insere um filho � direita de um dado n�
    Retorna 1 se a inser��o for com sucesso,
    Caso contr�rio 0  */
int insereDireita(tArvBin T, int vPai, int vFilho ) {
	tNo *f, *p, *novoNo;
	/*Verifica se o elemento j� existe*/
	f = busca(T, vFilho);
	if (f != NULL)
        return 0;  /*Err: dado j� existe*/

	/*Busca o pai e verifica se possui filho direito*/
	p = busca(T, vPai);
  	if (p == NULL)
		return 0; /*Err: pai n�o encontrado*/
	if (p->dir != NULL)
		return 0; /*Err: filho dir j� existe*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
		return (0);  /*Err: mem. insuf.*/

	novoNo->conteudo = vFilho;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	p->dir = novoNo;
	return 1;
}

/**Insere um filho � esquerda de um dado n�
    Retorna 1 se a inser��o for com sucesso, caso contr�rio 0*/
int insereEsq(tArvBin T, int vPai, int vFilho ) {
	tNo *f, *p, *novoNo;
	/*Verifica se o elemento j� existe*/
	f = busca(T, vFilho);
	if (f != NULL)
        return 0;  /*Err: dado j� existe*/

	/*Busca o pai e verifica se possui filho da esq*/
	p = busca(T, vPai);
  	if (p == NULL)
		return 0; /*Err: pai n�o encontrado*/
	if (p->esq != NULL)
		return 0; /*Err: filho esq j� existe*/

	novoNo = malloc(sizeof(tNo));
	if (novoNo == NULL)
		return 0;  /*Err: mem. insuf.*/

	novoNo->conteudo = vFilho;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	p->esq = novoNo;
	return 1;
}

/**Exibe o conte�do de uma �rvore em pr�-ordem*/
void exibePreOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	printf("%d   ", T->conteudo);
	if (T->esq != NULL)
		exibePreOrdem(T->esq);

 	if (T->dir != NULL)
		exibePreOrdem(T->dir);
}

/**Exibe o conte�do de uma �rvore em pr�-ordem*/
void exibeInOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	if (T->esq != NULL)
		exibeInOrdem(T->esq);

    printf("%d   ", T->conteudo);

 	if (T->dir != NULL)
		exibeInOrdem(T->dir);

}

/**Exibe o conte�do de uma �rvore em pr�-ordem*/
void exibePosOrdem(tArvBin T) {
	if (T == NULL)
		return ;

	if (T->esq != NULL)
		exibePosOrdem(T->esq);
	if (T->dir != NULL)
		exibePosOrdem(T->dir);

	printf("%d   ", T->conteudo);
}


