# include <stdio.h>
# include <math.h>

// 4 pois a primeira coluna deve ter 'error_order / 2' elementos
# define numElememsFirstCol 16
# define ORDEM_ERRO 8

void romberg(double array[]);
double trapz(double a, double b, int n);

// exemplo
// aproximar a integral de exp(-x*x), de 0 a 1
double f(double t) {
    double g = 9.81,
            m = 77.08,
            cd = 0.28;
    return sqrt((g*m)/cd) * tanh(sqrt((g*cd)/m)*t);
}

int main (void){

    // letra A:
    double a = 0;
    double b = 10.45;
    double h = 10.45/10;
    int n = (int)((b - a) / h);


    double coluna_F1[numElememsFirstCol];
    for (int i = 0; i < numElememsFirstCol; i++){
        coluna_F1[i] = trapz(a, b, pow(2, i) * n);
    }
    romberg(coluna_F1);

}

//Método dos trapézios
double trapz(double a, double b, int n){
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
    printf ("\n\nAprox O(h^%d) = %.16f", ORDEM_ERRO, array[0]);
}
