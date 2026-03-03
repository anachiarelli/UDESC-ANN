#include <stdio.h>
#include "math.h"
#define LEN 13

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
    int numParabolas = subintervalos / 2;

    for (int i = 1; i < subintervalos; i = i + 2) {
        soma += y[i-1] + 4 * y[i] + y[i + 1];
    }

    soma *= (h/3.0);

    return soma;
}

int main() {

    double t[LEN] = {0};
    for (int i = 1; i < LEN; i++) {
        t[i] = t[i-1] + 0.5;
    }

    double v[LEN] = {0, 1.2, 2.19, 3.38, 4.24, 4.72, 6.21, 7.16, 8.21, 8.7, 9.65, 10.83, 11.29};

    double soma = 0;
    for (int i = 0; i < LEN; i++) {
        soma += v[i];
    }
    printf("Somar e dividir por 2: %.16f\n", soma/2);

    printf("TRAPÉZIOS: %.16f\n", trapz_sem_f(t, v));

    printf("SIMPSON: %.16f\n", simpson_sem_f(t, v));
    return 0;
}
