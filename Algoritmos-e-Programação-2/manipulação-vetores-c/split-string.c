#include <stdio.h>

#define MAX 101

int splitstring(char* pstring, char** tokens){
    int i = 0;
    int maxtokens = 0;
    char* piniciopalavra = NULL;
    while(*(pstring + i) != '\0'){

        if(*(pstring + i) != ' ' && *(pstring + i) != '\0'){
            piniciopalavra = pstring + i;
            while(*(pstring + i) != ' ' && *(pstring + i) != '\0'){
                i++;
        }
    }
        if(*(pstring + i) == ' ' || *(pstring + i) == '\0'){
            *(pstring + i) = '\0';
            *(tokens + maxtokens) = piniciopalavra;
            maxtokens++;
            piniciopalavra = NULL;
            i++;
            while(*(pstring + i) == ' '){
                i++;
            }
        }

    }

    return maxtokens;
}

int main(){

    char string[MAX];
    char* tokens[MAX];
    scanf(" %[^\n]", string);
    int maxtokens = splitstring(string, tokens);

    for(int i=0; i<maxtokens; i++){
        printf("String %d: %s\n", i+1, (*(tokens+i)));
    }


    return 0;
}