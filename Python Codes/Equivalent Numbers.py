# cook your dish here
from math import log

def solve(A,B):
    lna = log(A)
    lnb = log(B)
    for y in range(1, 501):
        if ((y*lnb)/lna).is_integer():
            return True
    return False
    
T=int(input())
for _ in range(T):
    A,B=map(int, input().split(' '))
    if solve(A,B):
        print('yes')
        
    else:
        print('no')
    
