#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char vehicle[10], dayName[20];

    // Função para validar o formato do veículo
    int validateVehicleFormat(char *vehicle) {
        int size = strlen(vehicle);
        if ((size == 8 || size == 7) &&
            ((isalpha(vehicle[0]) && isalpha(vehicle[1]) && isalpha(vehicle[2]) &&
              isdigit(vehicle[size - 1])) ||
             (isalpha(vehicle[0]) && isalpha(vehicle[1]) && isalpha(vehicle[2]) &&
              isalpha(vehicle[3]) && isdigit(vehicle[size - 1])))) {
            return 1;
        }

        return 0;
    }

    // Função para validar o dia da semana
    int validateDayOfWeek(char *day) {
        return (strcmp(day, "SEGUNDA-FEIRA") == 0 || strcmp(day, "TERCA-FEIRA") == 0 ||
                strcmp(day, "QUARTA-FEIRA") == 0 || strcmp(day, "QUINTA-FEIRA") == 0 ||
                strcmp(day, "SEXTA-FEIRA") == 0 || strcmp(day, "SABADO") == 0 ||
                strcmp(day, "DOMINGO") == 0);
    }

    scanf("%s", vehicle);

    for (int i = 0; i < strlen(vehicle); i++) {
        vehicle[i] = toupper(vehicle[i]);
    }

    scanf("%s", dayName);

    int lastDigitVehicle = vehicle[strlen(vehicle) - 1] - '0';

    // Validação e exibição de mensagens
    if (!validateVehicleFormat(vehicle)) {
        printf("Placa invalida\n");
        if (!validateDayOfWeek(dayName)) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    } 
    if (!validateDayOfWeek(dayName)) {
        printf("Dia da semana invalido\n");
        return 0;
    } 
    else if (strcmp(dayName, "SABADO") == 0 || strcmp(dayName, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {    
        for (int i = 0; i < strlen(dayName); i++) {
            dayName[i] = tolower(dayName[i]);
        }
        if (strcmp(dayName, "segunda-feira") == 0 || strcmp(dayName, "terca-feira") == 0 ||
            strcmp(dayName, "quarta-feira") == 0 || strcmp(dayName, "quinta-feira") == 0 ||
            strcmp(dayName, "sexta-feira") == 0) {
            if ((lastDigitVehicle == 0 || lastDigitVehicle == 1) && strcmp(dayName, "segunda-feira") == 0) {
                printf("%s nao pode circular %s\n", vehicle, dayName);
            } else if ((lastDigitVehicle == 2 || lastDigitVehicle == 3) && strcmp(dayName, "terca-feira") == 0) {
                printf("%s nao pode circular %s\n", vehicle, dayName);
            } else if ((lastDigitVehicle == 4 || lastDigitVehicle == 5) && strcmp(dayName, "quarta-feira") == 0) {
                printf("%s nao pode circular %s\n", vehicle, dayName);
            } else if ((lastDigitVehicle == 6 || lastDigitVehicle == 7) && strcmp(dayName, "quinta-feira") == 0) {
                printf("%s nao pode circular %s\n", vehicle, dayName);
            } else if ((lastDigitVehicle == 8 || lastDigitVehicle == 9) && strcmp(dayName, "sexta-feira") == 0) {
                printf("%s nao pode circular %s\n", vehicle, dayName);
            } else {
                printf("%s pode circular %s\n", vehicle, dayName);
            }
        }
    }

    return 0;
}