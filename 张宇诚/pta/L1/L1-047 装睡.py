N = int(input())
for i in range(0, N) :
    name, a, b = input().split()
    a, b = int(a), int(b)
    if a < 15 or a > 20 :
        print(name)
    elif b < 50 or b > 70 :
        print(name)