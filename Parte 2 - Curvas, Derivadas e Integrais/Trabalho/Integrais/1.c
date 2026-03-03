#include <stdio.h>
#include "math.h"

// exemplo 1:
double func1(double x) {
    return sqrt(sin(cos(log(x*x+1)+2)+3)+4);
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
    printf("%i subintervalos = %.16f\n", n, soma);
}

int main() {

    double a = -1.789;
    double b = 1.073;
    int n_length = 12;
    int ns[12] = {3, 21, 48, 63, 82, 149, 152, 494, 600, 791, 1404, 9288};
    for (int i = 0; i < n_length; i++) {
        int n = ns[i];
        trapz(func1, a, b, n);
    }
    return 0;
}
