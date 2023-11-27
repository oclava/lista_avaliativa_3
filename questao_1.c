#include <stdio.h>

int valorRomano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanoParaDecimal(char *romano) {
    int resultado = 0;
    int i;

    for (i = 0; romano[i] != '\0'; i++) {
        if (valorRomano(romano[i]) >= valorRomano(romano[i + 1])) {
            resultado += valorRomano(romano[i]);
        } else {
            resultado -= valorRomano(romano[i]);
        }
    }

    return resultado;
}

int main() {
    char numeroRomano[20];
    int numeroDecimal;

    printf("Digite um numero romano: ");
    scanf("%s", numeroRomano);

    int resultado = romanoParaDecimal(numeroRomano);

    printf("%s na base 10: %d\n", numeroRomano, resultado);

    // Conversão para binário
    int decimalParaBinario = resultado;
    int binario[32];
    int i = 0;

    if (decimalParaBinario == 0) {
        printf("A representacao binaria e: 0\n");
    } else {
        while (decimalParaBinario > 0) {
            binario[i] = decimalParaBinario % 2;
            decimalParaBinario = decimalParaBinario / 2;
            i++;
        }

        printf("%s na base 2: ", numeroRomano);
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");
    }

    // Conversão para hexadecimal
    int decimalParaHexadecimal = resultado;
    char hexadecimal[100];
    i = 0;

    if (decimalParaHexadecimal == 0) {
        printf("A representacao hexadecimal e: 0\n");
    } else {
        while (decimalParaHexadecimal > 0) {
            int resto = decimalParaHexadecimal % 16;
            if (resto < 10) {
                hexadecimal[i] = resto + '0';
            } else {
                hexadecimal[i] = resto + 'A' - 10;
            }
            decimalParaHexadecimal = decimalParaHexadecimal / 16;
            i++;
        }

        printf("%s na base 16: ", numeroRomano);
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", hexadecimal[j]);
        }
        printf("\n");
    }

    return 0;
}
