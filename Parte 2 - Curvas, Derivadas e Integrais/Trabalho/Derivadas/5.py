import numpy as np
import math

# x0 = ponto onde a função será derivada
# x = lista de coordenadas na proximidade de x0
# y = cálculo da função em todos os pontos x
# k = ordem da derivada

def coeffs_dif_fin(x0, x, k):
    n = len(x)
    A, B = [[1]* n], [0]
    for i in range(1, n):
        # construção da matriz A
        row_i = [xi ** i for xi in x]
        A.append(row_i)
        # construção da matriz B
        if i < k:
            B.append(0)
        elif i == k:
            B.append(math.factorial(k))
        else:
            numer = math.factorial(i)
            denom = math.factorial(i - k)
            el = (numer / denom) * x0 ** (i - k)
            B.append(el)
    return np.linalg.solve(A, B)
        
def dif_fin(coeffs, y):
    return sum(ci * yi for ci, yi in zip(coeffs, y))
        

if __name__ == '__main__':
    # exemplo 1:
    def f(x):
        return math.cos(math.sin(math.log(x**2)))
    x0 = 0.9828
    k = 2
    n = 10 # numero de pontos igualmente espaçados
    # queremos pontos no intervalo [x0-e, x0+e]
    # ao diminuir o epsilon (e) os pontos são cada vez mais próximos
    e = 0.001
    x = [0.7472, 0.8415, 0.863, 0.97, 1.0001, 1.0855, 1.1328, 1.2328]
    y = [f(xi) for xi in x]
    
    coeffs = coeffs_dif_fin(x0, x, k)
    aprox = dif_fin(coeffs, y)
    print(f'{coeffs = }')
    print(f'{aprox = }')
