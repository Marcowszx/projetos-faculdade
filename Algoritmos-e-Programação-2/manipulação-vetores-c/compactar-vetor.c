#include <stdio.h>

int compactar(int* pvetor, int n){
    for(int i = 0; i < n; ){
        if((*(pvetor + i)) < 0){
            for(int j = i; j < n-1; j++){
                *(pvetor + j) = *(pvetor + j + 1);
            }
            n--;
        }
        else{
            i++;
        }
    }

    return n;

}

int main(){
    int n;
    printf("\nDigite o tamanho do vetor desejado: ");
    scanf("%d", &n);
    int vetor[n];
    printf("Preencha o vetor (%d inteiros) que será compactado (números negativos serão removidos): ", n);
    for(int i=0; i<n; i++){
        scanf("%d", vetor+i);
    }

    n = compactar(vetor, n);
    printf("Esse é o vetor compactado: ");
    for(int i = 0; i<n; i++){
        printf("%d ", *(vetor+i));
    } printf("\n\n");


    return 0;
}