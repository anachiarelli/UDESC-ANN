#include <stdio.h>
#include "math.h"

double f(double t) {
    double g = 9.81,
           m = 77.08,
           cd = 0.28;
    return sqrt((g*m)/cd) * tanh(sqrt((g*cd)/m)*t);
}

void trapz(double(*f)(double), double a, double b, int n) {
    double soma = 0;
    double h = (double)(b-a)/(double)n;
    for (int k = 1; k < n; k++) {
        soma += f(a + k * h);
    }
    soma *= 2;
    soma += f(a);
    soma += f(b);
    soma *= (h/2.0);
    printf("Area aprox = %.16f\n", soma);
}

int main() {

    double a = 0;
    double b = 10.45;
    int n = 32; // número de intervalos

    trapz(f, a, b, n);

    return 0;
}
