#include <stdio.h>
#include <math.h>

int main() {
    double principal; 
    double taxa_juros;
    int periodo;

    scanf("%d", &periodo);

    scanf("%lf", &principal);

    scanf("%lf", &taxa_juros);

    double total_acumulado = 0.0;
    for (int i = 1; i <= periodo; ++i) {
        principal *= (1 + taxa_juros);
        total_acumulado += principal;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, total_acumulado);
    }

    return 0;
}
