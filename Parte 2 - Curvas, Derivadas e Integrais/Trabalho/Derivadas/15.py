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
    x0 =  1.41805
    err_order = 6
    
    def F1(h):
        return (func(x0 + h) - func(x0)) / h
    
    
    col_F1 = [-4.118662183024201, -3.88549041853296, -3.7363433495394993, -3.6521622770840168, -3.607483813544306, -3.5844747101695305]
    
    aprox = richardson(col_F1)
    
    print(f'{aprox = }')
