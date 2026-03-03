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
        return x**2 * math.cos(x - 1) * math.exp(-3 * x ** 2)
    def p(xp):
        x0 = 0.5546
        n = 10 # numero de pontos igualmente espaçados
        # queremos pontos no intervalo [x0-e, x0+e]
        # ao diminuir o epsilon (e) os pontos são cada vez mais próximos
        e = 0.001
        x = [0.3361, 0.3564, 0.4536, 0.4817, 0.529, 0.5991, 0.61, 0.6635, 0.7218, 0.8017]
        y = [f(xi) for xi in x]
        
        coeffs = coeffs_dif_fin(x0, x, 1)
        f_1 = dif_fin(coeffs, y)
        
        coeffs = coeffs_dif_fin(x0, x, 2)
        f_2 = dif_fin(coeffs, y)
        
        coeffs = coeffs_dif_fin(x0, x, 3)
        f_3 = dif_fin(coeffs, y)
        
        coeffs = coeffs_dif_fin(x0, x, 4)
        f_4 = dif_fin(coeffs, y)
        
        coeffs = coeffs_dif_fin(x0, x, 5)
        f_5 = dif_fin(coeffs, y)
        
        
        return f(x0) + f_1*(xp - x0) + (f_2/np.math.factorial(2))*((xp - x0)**2) + (f_3/np.math.factorial(3))*((xp - x0)**3) + ((f_4/np.math.factorial(4)) * np.power((xp - x0), 4)) + ((f_5/np.math.factorial(5)) * np.power((xp - x0), 5))
    
    
    values = [0.3477, 0.4348, 0.4364, 0.5362, 0.795]
    px = [p(vi) for vi in values]
    print(f'{px = }')

    fx_menos_px = [np.abs(f(vi) - p(vi)) for vi in values]
    print(f'{fx_menos_px = }')
