#include <stdio.h>
#include <string.h>

#define MAX 150

typedef struct{
    char nome[51];
    float nota1;
    float nota2;
} ALUNO;

int indicealunonome(const ALUNO* paluno, const int* pcadastrados){

    while(1){
        char nomealuno[51];
        printf("\nDigite o nome do aluno: ");
        scanf(" %[^\n]", nomealuno);
        
        int i;
        for(i=0; i<(*pcadastrados); i++){
            if(strcmp((paluno+i)->nome, nomealuno)==0){
                break;
            }
        }

        if(i==(*pcadastrados)){
            printf("\nAluno não encontrado!");
            continue;
        }
        else{
            return i;
        }
    }
    
}

void menu(int* popcao){

    int leitura;
    printf("\n\n--- Olá! Essas são as ações disponíveis: ---\n\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Calcular media de aluno\n");
    printf("3 - Alterar notas de aluno\n");
    printf("4 - Mostrar alunos\n");
    printf("5 - Sair\n");
    printf("\n--------------------------------------------\n\n");

    printf("Digite o número da opção desejada: ");
    leitura = scanf("%d", popcao);

    if(leitura!=1 || (*popcao)<1 || (*popcao)>5){
        do{
            int c;
            while((c=getchar())!='\n' && c!=EOF);
            printf("Opção inválida! Digite novamente: ");
            leitura = scanf("%d", popcao);
        } while(leitura!=1 || (*popcao)<1 || (*popcao)>5);
    }

    return;
}

void cadastrar(ALUNO* paluno, int* pcadastrados){

    if((*pcadastrados)<MAX){
        while((*pcadastrados)<MAX){

            printf("\n-- Cadastrando o aluno < %d > --\n", (*pcadastrados)+1);

            printf("Nome do aluno: ");
            scanf(" %[^\n]", (paluno + (*pcadastrados))->nome);

            printf("Nota 1 do aluno: ");
            int leitura = scanf(" %f", &((paluno + (*pcadastrados))->nota1));
            if(leitura!=1){
                do{
                    int c;
                    while((c=getchar())!='\n' && c!=EOF);
                    printf("Nota inválida! Digite novamente: ");
                    leitura = scanf(" %f", &((paluno + (*pcadastrados))->nota1));
                } while(leitura!=1);
            }

            printf("Nota 2 do aluno: ");
            leitura = scanf(" %f", &((paluno + (*pcadastrados))->nota2));
            if(leitura!=1){  
                do{
                    int c;
                    while((c=getchar())!='\n' && c!=EOF);
                    printf("Nota inválida! Digite novamente: ");
                    leitura = scanf(" %f", &((paluno + (*pcadastrados))->nota2));
                } while(leitura!=1);
            }

            (*pcadastrados)+=1;

            if((*pcadastrados)<MAX){
                printf("\nDeseja cadastrar o próximo aluno?\n");
                printf("1 - Sim\n");
                printf("2 - Não\n");
                printf("Digite a opção desejada: ");
                int opcao;
                int leitura = scanf("%d", &opcao);
                if(leitura!=1 || opcao<1 || opcao>2){
                    do{
                        int c;
                        while((c=getchar())!='\n' && c!=EOF);
                        printf("Opcao inválida! Digite novamente: ");
                        leitura = scanf("%d", &opcao);
                    } while(leitura!=1 || (opcao!=1 && opcao!=2));
                }
                if(opcao==1){
                    continue;
                }
                else{
                    printf("\n...Voltando ao menu...\n");
                    break;
                }
            }
            else{
                printf("\nMáximo de cadastros atingido!\n...Voltando ao menu...\n");
                break;
            }
        }
    }
    else{
        printf("\nMáximo de cadastros atingido!\n...Voltando ao menu...\n");
    }

    return;
}

float calcularmediaaluno(const ALUNO* paluno, const int* pcadastrados){

    int indicealuno = indicealunonome(paluno, pcadastrados);
    float mediaaluno = (((paluno+indicealuno)->nota1) + ((paluno+indicealuno)->nota2))/2;
    return mediaaluno;
}

void mostrarmedia(const ALUNO* paluno, const int* pcadastrados){

    if((*pcadastrados)<1){
        printf("\nNão foi possível encontrar cadastros. Retornando ao menu...\n");
        return;
    }

    while(1){
            float mediaaluno = calcularmediaaluno(paluno, pcadastrados);
            printf("\nA média é: %.2f", mediaaluno);
            printf("\n\nDeseja calcular a média de outro aluno?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("Digite a opção desejada: ");
            int escolha;
            int leitura = scanf("%d", &escolha);
            if(leitura!=1 || (escolha!=1 && escolha!=2)){
                do{
                    int c;
                    while((c=getchar())!='\n' && c!=EOF);
                    printf("\nOpção inválida! Digite novamente: ");
                    leitura = scanf("%d", &escolha);
                } while(leitura!=1 || (escolha!=1 && escolha!=2));
            }
            if(escolha == 1){
                continue;
            }
            else{
                break;
            }
        }
        return;
}

void atualizarnotas(ALUNO* paluno, const int* pcadastrados){

    if((*pcadastrados)<1){
        printf("\nNão foi possível encontrar cadastros. Retornando ao menu...\n");
        return;
    }

    while(1){
    int indicealuno = indicealunonome(paluno, pcadastrados);
    printf("\n\nAs notas atuais de < %s > são:\n", (paluno+indicealuno)->nome);
    printf("Nota 1 = %.2f\n", (paluno+indicealuno)->nota1);
    printf("Nota 2 = %.2f\n\n", (paluno+indicealuno)->nota2);

    printf("Digite o novo valor da nota 1 de < %s >: ", (paluno+indicealuno)->nome);
    int leitura = scanf("%f", &((paluno+indicealuno)->nota1));
    if(leitura!=1){
        do{
            int c;
            while((c=getchar())!='\n' && c!=EOF);
            printf("Valor inválido! Digite novamente o novo valor da nota 1 de < %s >: ", (paluno+indicealuno)->nome);
            leitura = scanf("%f", &((paluno+indicealuno)->nota1));
        } while(leitura!=1);
    }

    printf("Digite o novo valor da nota 2 de < %s >: ", (paluno+indicealuno)->nome);
    leitura = scanf("%f", &((paluno+indicealuno)->nota2));
    if(leitura!=1){
        do{
            int c;
            while((c=getchar())!='\n' && c!=EOF);
            printf("Valor inválido! Digite novamente o novo valor da nota 2 de < %s >: ", (paluno+indicealuno)->nome);
            leitura = scanf("%f", &((paluno+indicealuno)->nota2));
        } while(leitura!=1);
    }

    printf("\nAs notas atuais de < %s > são:\n", (paluno+indicealuno)->nome);
    printf("Nota 1 = %.2f\n", (paluno+indicealuno)->nota1);
    printf("Nota 2 = %.2f\n\n", (paluno+indicealuno)->nota2);

    printf("\nDeseja alterar as notas de outro aluno?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        printf("Digite a opção desejada: ");
        int escolha;
        int leitura2 = scanf("%d", &escolha);
        if(leitura2!=1 || (escolha!=1 && escolha!=2)){
            do{
                int c;
                while((c=getchar())!='\n' && c!=EOF);
                printf("\nOpção inválida! Digite novamente: ");
                leitura = scanf("%d", &escolha);
            } while(leitura2!=1 || (escolha!=1 && escolha!=2));
        }
        if(escolha == 1){
            continue;
        }
        else{
            break;
        }
        return;
    }


}

void mostraralunos(const ALUNO* paluno, const int* pcadastrados){
    if((*pcadastrados)<1){
        printf("\nNão foi possível encontrar cadastros. Retornando ao menu...\n");
        return;
    }
    else{
    printf("\n\n--- Lista do(s) %d cadastro(s) realizado(s) ---\n\n", *pcadastrados);
    for(int i=0; i<(*pcadastrados); i++){
        printf("Nome do aluno: %s\n", (paluno+i)->nome);
        printf("Nota 1 = %.2f\n", (paluno+i)->nota1);
        printf("Nota 2 = %.2f\n", (paluno+i)->nota2);
        printf("Média das notas = %.2f\n\n", (((paluno+i)->nota1) + ((paluno+i)->nota2))/2);
    }
    printf("------------------------------------------------");
}
    return;
}

int main(){

    ALUNO aluno[MAX];
    int opcao;
    int cadastrados=0;
    do{
        menu(&opcao);

        switch(opcao){

            case 1:
            cadastrar(aluno, &cadastrados);
            break;

            case 2:
            mostrarmedia(aluno, &cadastrados);
            break;

            case 3:
            atualizarnotas(aluno, &cadastrados);
            break;

            case 4:
            mostraralunos(aluno, &cadastrados);
            break;

            default:
            printf("\nPrograma encerrado.\n\n");
            break;

        }

    } while(opcao!=5);

    return 0;
}
