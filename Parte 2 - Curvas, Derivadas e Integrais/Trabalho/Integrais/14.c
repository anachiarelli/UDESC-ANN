#include <stdio.h>
#include "math.h"
#define LEN 7

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

    double inc = 10.0;
    double t[LEN] = {0};
    for (int i = 1; i < LEN; i++) {
        t[i] = t[i-1] + inc;
    }

    double v[LEN] = {211.01, 121.59, 140.84, 180.97, 248.56, 283.53, 233.11};

    // necessário transformar em km/s:
    for (int i = 0; i < LEN; i++) {
        v[i] = v[i] / 3600;
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
