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

void decimalParaBinario(int decimal) {
    int binario[32];
    int i = 0;

    if (decimal == 0) {
        printf("A representacao binaria e: 0\n");
        return;
    }

    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("%d na base 2: ", decimal);  // Corrigido para imprimir o número decimal
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void decimalParaHexadecimal(int decimal) {
    char hexadecimal[100];
    int i = 0;

    if (decimal == 0) {
        printf("A representacao hexadecimal e: 0\n");
        return;
    }

    while (decimal > 0) {
        int resto = decimal % 16;
        if (resto < 10) {
            hexadecimal[i] = resto + '0';
        } else {
            hexadecimal[i] = resto + 'A' - 10;
        }
        decimal = decimal / 16;
        i++;
    }

    printf("A representacao hexadecimal e: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

int main() {
    char numeroRomano[20];
    int numeroDecimal;

    printf("Digite um numero romano: ");
    scanf("%s", numeroRomano);

    int resultado = romanoParaDecimal(numeroRomano);

    printf("%s na base 10: %d\n", numeroRomano, resultado);

    numeroDecimal = resultado;
    decimalParaBinario(numeroDecimal);
    decimalParaHexadecimal(numeroDecimal);

    return 0;
}
