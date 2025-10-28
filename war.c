#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QttOfTerritory 5

struct Territory {
    char name[30];
    char collor[10];
    int troops;
};

int stringIsNumber(char string[50]) {
    if (string[0] == '\0') return 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    struct Territory territories[QttOfTerritory];

    printf("= = = = = Bem vindo ao Jogo War ! = = = = =\n");
    printf("Digite os dados para os %d territorios.\n\n", QttOfTerritory);

    for (int i = 0; i < QttOfTerritory; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);
        printf("Digite o nome do territorio: ");
        scanf(" %[^\n]", territories[i].name);

        do {
            printf("Digite a cor do exercito ");
            scanf(" %[^\n]", territories[i].collor);
            if (stringIsNumber(territories[i].collor)) printf("( Numero digitado )\n");
        } while (stringIsNumber(territories[i].collor));

        char data[100];
        do {
            printf("Quantidade de tropas: ");
            scanf(" %[^\n]", data);
            if (!stringIsNumber(data)) printf("( Letra digitada )\n");
        } while (!stringIsNumber(data));

        territories[i].troops = atoi(data);
        printf("\n");
    }
    
    printf("===== TERRITORIOS CADASTRADOS =====\n\n");

    for (int i = 0; i < QttOfTerritory; i++) {
        printf("> > > Territorio %d < < <\n", i + 1);
        printf("Nome: %s\n", territories[i].name);
        printf("Cor do Exercito: %s\n", territories[i].collor);
        printf("Quantidade de Tropas: %d\n", territories[i].troops);
        printf("---------------------\n");
    }
    
    printf("cadastro finalizado com sucesso !\n\n");
    return 0;
}

