'''
input : 
4 4 1 2 -3 1 -1 0 -1
3 2 3 1 -2 0 1
explain : 
A = x^4 - 3x^2 - x - 1
B = 3x^2 - 2x + 1
A / B = 0.3x^2 + 0.2x - 1 ... -3.1x
do :
K = A
1.  x^4 / 3x^2 = 1/3x^2
    K = K - 1/3x^2 * B = 2/3x^3 - 10/3x^2 - x - 1
2.  2/3x^3 / 3x^2 = 2/9x
    K = K - 2/9x * B = -26/9x^2 - 11/9 - 1
3.  -26/9x^2 / 3x^2 = -26/27
    K = K - -26/27 * B = -85/27x - 1/27
'''

import copy
a = [int(v) for v in input().split()]
b = [int(v) for v in input().split()]
A = [] #[[指数, 系数]]
B = []
k = a[0]
for i in range(1, k * 2) : 
    if i % 2 == 0 : continue
    A.append([a[i], a[i + 1]])
k = b[0]
for i in range(1, k * 2) : 
    if i % 2 == 0 : continue
    B.append([b[i], b[i + 1]])

#多项式相减
def minus(A, B) : 
    C = copy.deepcopy(A)
    visited = []
    for a in C : 
        for b in B : 
            if a[0] == b[0] : 
                a[1] -= b[1]
                visited.append(b)
    for b in B : 
        if not b in visited : 
            C.append([b[0], -b[1]])
    C.sort(key = lambda x:-x[0])
    return C

#多项式乘单项式
def multply(A, B) : 
    C = []
    for a in A : 
        C.append([a[0] + B[0], a[1] * B[1]])
    return C

#多项式去系数0
def delNull(A) : 
    S = []
    for a in A : 
        if float("{:.1f}".format(a[1])) != 0 : 
            S.append(a)
    return S

#打印多项式
def myprint(S) : 
    if len(S) == 0 : 
        print("0 0 0.0", end = "")
    else : 
        print(len(S), end = " ")
        for i in range(0, len(S)) : 
            print(f"{S[i][0]} {S[i][1]:.1f}", end="")
            if i != len(S) - 1 : 
                print(" ", end = "")

K = copy.deepcopy(A)
S = []
while K[0][0] >= B[0][0] : 
    e = K[0][0] - B[0][0]
    k = K[0][1] / B[0][1]
    S.append([e, k])
    m = multply(B, [e, k])
    del K[0]
    del m[0]
    K = minus(K, m)

myprint(delNull(S))
print()
myprint(delNull(K))
print()