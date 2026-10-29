#include <stdio.h>

#define MAX 101

int tamanhostring(const char* pstring){
    int tamanho=0;
    for(int i=0; (*(pstring +i)) != '\0'; i++){
        tamanho++;
    }
    return tamanho;
}

void inverterstring(char* pinicio){
    int restante = tamanhostring(pinicio) - 1;
    char* pfinal = (pinicio + restante);
    
    for(int i=0; (pinicio + i) < (pfinal - i); i++){
        char aux = *(pinicio + i);
        *(pinicio + i) = *(pfinal - i);
        *(pfinal - i) = aux;
    }
    
    return;
}

int main(){

    char string[MAX];
    printf("\nDigite a string (de até %d caracteres) que deseja inverter: ", MAX-1);
    scanf(" %[^\n]", string);

    inverterstring(string);
    printf("A string invertida é: %s\n", string);

    inverterstring(string);
    printf("A string normalizada é: %s\n\n", string);

    return 0;
}