#include <stdio.h>
#include "math.h"
#define LEN 17

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

    double inc = 0.75;
    double t[LEN] = {0};
    for (int i = 1; i < LEN; i++) {
        t[i] = t[i-1] + inc;
    }

    //double r[LEN] = {9.75, 9.45, 8.84, 8.62, 8.17, 7.67, 7.47, 6.77, 6.45, 6.12, 5.65, 5.36, 4.94, 4.34, 4.05, 3.47, 3.13};

    for (int i = 0; i < LEN; i++) {
        printf("(%.2f, %.2f)\n", t[i], r[i]);
    }

    double soma = 0;
    for (int i = 0; i < LEN; i++) {
        soma += r[i];
    }
    printf("SOMAR E DIVIDIR: %.16f\n", soma * inc);

    printf("TRAPÉZIOS: %.16f\n", trapz_sem_f(t, r));

    printf("SIMPSON: %.16f\n", simpson_sem_f(t, r));
    return 0;
}
