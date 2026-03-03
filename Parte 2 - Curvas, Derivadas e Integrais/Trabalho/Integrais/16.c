#include <stdio.h>
#include "math.h"
#define LEN 19

double trapz_sem_f(double x[], double y[]) {
    double soma = 0;
    for (int i = 0; i < LEN -1; i++) {
        double altura = y[i] + y[i+1],
                base = x[i+1] - x[i];
        soma += (base * altura)/2;
    }

    return soma;
}

double simpson_sem_f(double x[], double y[]) {
    double soma = 0;
    double h = (double) (x[LEN-1] - x[0]) / (double)(LEN -1);
    int subintervalos = LEN - 1;

    for (int i = 1; i < subintervalos; i = i + 2) {
        soma += y[i-1] + 4 * y[i] + y[i + 1];
    }

    soma *= (h/3.0);

    return soma;
}

int main() {

    double inc = 5;
    double t[LEN] = {0};
    for (int i = 1; i < LEN; i++) {
        t[i] = t[i-1] + inc;
    }

    double v[LEN] = {0, 107, 231, 359, 513, 675, 827, 966, 1085, 1212, 1321, 1457, 1637, 1818, 2049, 2315, 2594, 2895, 3200};

    // necessário transformar em km/s:
    for (int i = 0; i < LEN; i++) {
        v[i] = v[i] / 3600;
    }

    for (int i = 0; i < LEN; i++) {
        printf("(%.2f, %.2f)\n", t[i], v[i]);
    }

    double soma = 0;
    for (int i = 0; i < LEN; i++) {
        soma += v[i];
    }
    printf("SOMAR E DIVIDIR: %.16f\n", soma * inc);

    printf("TRAPÉZIOS: %.16f\n", trapz_sem_f(t, v));

    printf("SIMPSON: %.16f\n", simpson_sem_f(t, v));
    return 0;
}
