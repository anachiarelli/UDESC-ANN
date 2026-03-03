import math

def simps(f, a, b, n):
    h = (b - a) / n
    soma_odd, soma_even = 0, 0
    for k in range(1, n, 2):
        soma_odd += f(a + k * h)
    for k in range(2, n, 2):
        soma_even += f(a + k * h)
    return (h/3) * (f(a) + 4 * soma_odd + 2 * soma_even + f(b))



def f(x):
    return math.exp(-x ** 2)
a = 0
b = 1
n = 50

print(simps(f, a, b, n))
