#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include "fila.h"

void menuPrincipal();
void menuGeraSenha();
void geraNormal();
void menuChamada();
void listaFila();

struct no *pInicio = NULL, *pFim = NULL, *nInicio = NULL, *nFim = NULL;

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    menuPrincipal();
    return 0;
};

void menuPrincipal(){
    char op;
    do{
        system("cls");
        printf("***Sistemas de Senhas ***\n");
        printf("***  MENU DE OPÇÕES   ***\n\n");
        printf("1 - Geração de Senha\n");
        printf("2 - Chamada de Senha\n");
        printf("3 - Listagem da Fila\n\n");
        printf("X - Sair do Programa\n\n");
        printf(">");
        scanf("%c", &op);
        switch((int)op){
        case 49:
            menuGeraSenha(0);
            break;
        case 50:
            chamaSenha();
            break;
        case 51:
            listaFila();
            break;
        }
    }while((int)op != 120 && (int)op != 88);
}

void menuGeraSenha(int senha){
    char op;
    do{
        system("cls");
        printf("***Sistemas de Senhas ***\n");
        printf("*** Geração de Senha  ***\n\n");
        printf("1 - Geração de Senha NORMAL\n");
        printf("2 - Geração de Senha PREFERENCIAL\n");
        if(senha){
            printf("\n A senha gerada foi: %d \n\n", senha);
        }
        printf("X - Voltar ao Menu de Opções \n\n");
        printf(">");
        scanf("%c", &op);
        switch((int)op){
        case 49:
            geraNormal();
            break;
        case 50:
            geraPreferencial();
            break;
        }
    }while((int)op != 120 && (int)op != 88);
    menuPrincipal();
}

void menuChamada(int senha, int tipo){
    char op;

    do{
        system("cls");
        printf("***Sistemas de Senhas ***\n");
        printf("*** Chamada de Senha  ***\n\n");
        if(senha){
            printf("\n Senha Chamada: %d", senha);
            if(tipo == 1){
                printf("\n Tipo: Preferencial");
            }else{
                printf("\n Tipo: Normal");
            }
            printf("\n\n1 - Chamar Outra senha\n");
        }else{
            printf("\n Nenhuma Senha Foi Inserida\n\n\n");
        }

        printf("X - Voltar ao Menu de Opções \n\n");
        printf(">");
        scanf("%c", &op);
        switch((int)op){
        case 49:
            chamaSenha();
            break;
        }

    }while((int)op != 120 && (int)op != 88);
    menuPrincipal();


}

void chamaSenha(){
    if(!vazia(pInicio)){
        int x = retira(&pInicio, &pFim);
        menuChamada(x, 1);
    }else if(!vazia(nInicio)){
        int x = retira(&nInicio, &nFim);
        menuChamada(x, 0);
    }else{
        menuChamada(0,0);
    }
}

void geraNormal(){
    int senha = (rand() % 998)+1;
    insere(&nInicio, &nFim, senha);
    menuGeraSenha(senha);
}

void geraPreferencial(){
    int senha = (rand() % 998)+1;
    insere(&pInicio, &pFim, senha);
    menuGeraSenha(senha);
}

void listaFila(){
    char op;
    do{
        int pos = 1;
        system("cls");
        printf("***Sistemas de Senhas ***\n");
        printf("*** Chamada de Senha  ***\n\n");
        consulta(pInicio, nInicio);
        printf("\n\nX- Voltar ao menu de opções\n");
        printf(">");
        scanf("%c", &op);

    }while((int)op != 88 && (int)op != 120);
    menuPrincipal();
}


