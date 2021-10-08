#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define troca(x, y) {int aux = x; x = y; y = aux;}



void selection(int vetor[], int n){
    int i, j, min;

    for(i = 0; i<n-1; i++){
        min = i;
        for(j = i+1; j< n; j++){
            if(vetor[j] < vetor[min])
                min = j;
        }
        troca(vetor[min], vetor[i]);
    }
}

int main(){
int vetor[10];

srand(time(NULL));

for(int i = 0; i<10; i++)
    vetor[i] = rand() % 50;

selection(vetor, 10);

for(int j = 0; j<10; j++)
    printf("%d ", vetor[j]);


}