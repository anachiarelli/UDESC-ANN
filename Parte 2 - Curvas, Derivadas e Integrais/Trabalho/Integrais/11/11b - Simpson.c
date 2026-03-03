#include <stdio.h>
#include "math.h"

double func(double t) {
    double g = 9.81,
            m = 77.08,
            cd = 0.28;
    return sqrt((g*m)/cd) * tanh(sqrt((g*cd)/m)*t);
}

void simps(double(*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        printf("O número de subintervalos deve ser par\n");
    }
    double soma = 0;
    int numParabolas = n/2;
    double h = (double)(b-a) / (double)n;

    for (int k = 0; k < numParabolas; k++) {
        double x0 = a + (2 * k) * h;
        double x1 = a + (2 * k + 1) * h;
        double x2 = a + (2 * k + 2) * h;
        soma += (f(x0) + 4 * f(x1) + f(x2));
    }
    soma *= (h/3.0);

    printf("Área aproximada: %.16f\n", soma);
}

int main() {
    double a = 0;
    double b = 10.45;
    int n = 16;

    simps(func, a, b, n);
    return 0;
}
