#include <stdio.h>
#include "math.h"
// Para ROMBERG:
# define numElememsFirstCol 16
# define ORDEM_ERRO 8

// f(x)
double f(double t) {
    double q = 9 + 4 * pow(cos(0.48 * t), 2);
    double c = 5* exp(-0.47*t) + 2 * exp(0.15*t);

    return q * c;
}

// Trapézios:
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
    printf("TRAPÉZIOS: %.16f\n", soma);
}


// Simpson:
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

    printf("SIMPSON: %.16f\n", soma);
}

// Romberg:
void romberg(double array[]){
    // i + 0 está calculando a coluna F2
    int numCols = ORDEM_ERRO / 2 - 1;
    for (int i = 0; i < numCols; i++){
        for (int j = 0; j < numCols; j++){
            double numer = pow(2, (i + 1) * 2) * array[j + 1] - array[j];
            double denom = pow(2, (i + 1) * 2) - 1;
            array[j] = numer / denom;
        }
    }
    printf ("ROMBERG: %.16f", ORDEM_ERRO, array[0]);
}

double trapz_romberg(double a, double b, int n){
    double soma = 0;
    double h = (double)(b - a) / (double)n;
    for (int i = 1; i < n; i++){
        double xi = a + i * h;
        soma += f(xi);
    }
    soma *= 2;
    soma += f(a);
    soma += f(b);
    soma *= (0.5 * h);
    return soma;
}


int main() {

    double a = 1.66;
    double b = 7.66;

    // Trapézios:
    int n_trapz = 19; // número de intervalos
    trapz(f, a, b, n_trapz);

    // Simpson:
    int n_simps = 12;
    simps(f, a, b, n_simps);

    // Romberg:
    double h = (b - a)/10;
    int n_romberg = (int)((b - a) / h);


    double coluna_F1[numElememsFirstCol];
    for (int i = 0; i < numElememsFirstCol; i++){
        coluna_F1[i] = trapz_romberg(a, b, pow(2, i) * n_romberg);
    }
    romberg(coluna_F1);

    return 0;
}
