#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[8];
    char diaSemana[20];  // Usar uma string para armazenar o dia da semana por extenso

    // Entrada da placa e do dia da semana
    printf("Digite a placa do carro (LLL-NNNN ou LLLNLNN): ");
    scanf("%s", placa);

    printf("Digite o dia da semana por extenso: ");
    scanf("%s", diaSemana);

    // Converte o dia da semana para minúsculas para facilitar a comparação
    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    }

    // Verifica o formato da placa
    if ((strlen(placa) == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) ||
        (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]))) {

        int diaSemanaNumerico;

        // Converte o dia da semana por extenso para um número decimal
        if (strcmp(diaSemana, "segunda-feira") == 0) {
            diaSemanaNumerico = 1;
        } else if (strcmp(diaSemana, "terca-feira") == 0) {
            diaSemanaNumerico = 2;
        } else if (strcmp(diaSemana, "quarta-feira") == 0) {
            diaSemanaNumerico = 3;
        } else if (strcmp(diaSemana, "quinta-feira") == 0) {
            diaSemanaNumerico = 4;
        } else if (strcmp(diaSemana, "sexta-feira") == 0) {
            diaSemanaNumerico = 5;
        } else if (strcmp(diaSemana, "sabado") == 0) {
            diaSemanaNumerico = 6;
        } else if (strcmp(diaSemana, "domingo") == 0) {
            diaSemanaNumerico = 7;
        } else {
            printf("Dia da semana invalido.\n");
            return 1;  // Encerra o programa se o dia da semana for inválido
        }

        // Verifica o dia da semana usando diaSemanaNumerico
        switch (diaSemanaNumerico) {
            case 1: // Segunda-feira
            case 2: // Terça-feira
            case 3: // Quarta-feira
            case 4: // Quinta-feira
            case 5: // Sexta-feira
                if (placa[6] == '0' || placa[6] == '1' || placa[6] == '2' || placa[6] == '3' || placa[6] == '4' || placa[6] == '5' || placa[6] == '6' || placa[6] == '7') {
                    printf("%s pode circular %s.\n", placa, diaSemana);
                } else {
                    printf("%s não pode circular %s.\n", placa, diaSemana);
                }
                break;
            case 6: // Sábado
            case 7: // Domingo
                printf("%s pode circular no fim de semana.\n", placa);
                break;
            default:
                printf("Dia da semana invalido.\n");
        }
    } else {
        printf("Placa invalida.\n");
    }

    return 0;
}
