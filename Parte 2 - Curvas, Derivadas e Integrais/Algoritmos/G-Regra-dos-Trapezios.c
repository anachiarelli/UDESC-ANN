#include <stdio.h>
#include "math.h"

// exemplo 1:
double func1(double x) {
    return exp(-x*x);
}

// exemplo 2:
double func2(double x) {
    return cos(x*x);
}

// exemplo 3:
double func3(double x) {
    return x*x+1;
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
    double b = 1;
    int n = 10; // número de intervalos

    trapz(func1, a, b, n);

    return 0;
}
