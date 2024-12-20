N = int(input())

def func(n) :
    s = 0
    a = 1
    for i in range(1, n + 1) :
        a *= i
        s += a;
    return s
    
print(func(N))