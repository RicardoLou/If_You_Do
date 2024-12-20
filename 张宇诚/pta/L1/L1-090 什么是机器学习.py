A, B = [int(v) for v in input().split()]

for i in range(0, 4) :
    print(B + A - (16 if i == 0 else 3 if i == 1 else 1 if i == 2 else 0) )