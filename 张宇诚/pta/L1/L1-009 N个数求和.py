import math as mt
import functools as ft

input()

li = input().split()

A = [] #分子
B = [] #分母

for s in li :
    a, b = [int(v) for v in s.split("/")]
    A.append(a)
    B.append(b)

lcm = int(ft.reduce(mt.lcm, B)) #最小公倍数

for i in range(0, len(A)) :
    A[i] *= lcm // B[i]

s = 0
for i in A :
    s += i

if s % lcm == 0 :
    print(int(s // lcm))
else :
    if int(s / lcm) != 0 : print(int(s // lcm), end=" ")
    a = int(abs(s) % lcm)
    if s < 0 :
        a *= -1
    gcd = mt.gcd(a, lcm) # 最大公约数
    print(f"{int(a // gcd)}/{int(lcm // gcd)}", end="")