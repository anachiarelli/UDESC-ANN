import math

# Método de integração de Romberg
# É o método de extrapolação de Richardson aplicado sobre a regra dos trapézios

def romberg(col1):
    col1 = [item for item in col1]
    n = len(col1)
    for j in range (n-1):
        temp_col = [0] * (n - 1 - j)
        for i in range (n - 1 - j):
            power = j + 1
            temp_col[i] = (4 ** power * col1[i + 1] - col1[i]) / (4 ** power - 1)
        col1[:n - 1 - j] = temp_col
    return col1[0]

def trapz(f, a, b, h):
    n = int((b - a) / h)
    sum_fx = 0
    for i in range(1, n):
        sum_fx += f(a + i * h)
    return (f(a) + 2 * sum_fx + f(b)) * h/2
    
    
def f(x):
    return math.cos(-x**2/3)
    
a, b = [0.5, 1.5]

h = 0.1
k = 6
hs = [h / 2** i for i in range(k)]
col1 = [trapz(f, a, b, hi) for hi in hs]

# encontre uma aproximação O(h^10)
r = romberg(col1)
print(r)
