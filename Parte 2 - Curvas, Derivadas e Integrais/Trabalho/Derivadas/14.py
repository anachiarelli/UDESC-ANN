import math
import numpy as np

def richardson(col_1):
    n = len(col_1)
    for i in range(n - 1):
        for j in range (n - 1 - i):
            numer = 2 ** (i+1) * col_1[j + 1] - col_1[j]
            denom = 2 ** (i+1) - 1
            value = numer/denom
            col_1[j] = value
    return col_1[0]
            
if __name__ == '__main__':

    # exemplo 1
    def func(x):
        return np.power(x, np.power(x, -x))
        
    #h = ?
    x0 = 2.0073
    err_order = 3
    
    def F1(h):
        return (func(x0 + h) - func(x0)) / h
    
    
    col_F1 = [0.9800091587883326, 1.01853632713415, 1.0338447553916055]
    
    aprox = richardson(col_F1)
    
    print(f'{aprox = }')
