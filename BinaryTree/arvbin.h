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
