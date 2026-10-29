#include <stdio.h>

#define MAX 10

void rotacionar_direita(int* pvetor, int vezes){
    for(int t=0; t<vezes; t++){
    int* pfinal = (pvetor+(MAX-1));
    int final = *pfinal;
        for(int i=0; (pfinal-i)!=(pvetor); i++){
            *(pfinal-i) = *((pfinal-i)-1);
        }
    *(pvetor) = final;
    }

    printf("\nEsse é o vetor rotacionado %d vezes à direita: ", vezes);
    for(int i=0; i<MAX; i++){
        printf("%d ", *(pvetor+i));
    }
    printf("\n");
    return;
}

int main(){

    int vetor[MAX];
    int rotacoes;
    printf("Preencha o vetor (%d inteiros): ", MAX);
    for(int i=0; i<MAX; i++){
        scanf("%d", vetor+i);
    }

    printf("\nDigite quantas vezes deseja rotacionar: ");
    scanf("%d", &rotacoes);
    rotacionar_direita(vetor, rotacoes);

    return 0;
}