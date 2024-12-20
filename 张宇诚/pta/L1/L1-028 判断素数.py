import math

def isPrime(n) :
    if n == 1 : 
        return False
    isPrm = True
    for i in range(2, int(math.sqrt(n)) + 1) :
        if i == n : continue
        if n % i == 0 :
            isPrm = False
    return isPrm

n = int(input())
for i in range(0, n) :
    a = int(input())
    if isPrime(a) :
        print("Yes")
    else : print("No")
