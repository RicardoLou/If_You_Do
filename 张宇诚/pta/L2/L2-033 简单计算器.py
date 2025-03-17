N = int(input())
S1 = [int(v) for v in input().split()]
S2 = input().split()

while len(S2) != 0 : 
    opt = S2[-1]
    del S2[-1]
    n1 = S1[-1]
    n2 = S1[-2]
    del S1[-1]
    del S1[-1]
    result = 0
    if opt == '+' : 
        result = n2 + n1
    elif opt == '-' : 
        result = n2 - n1
    elif opt == '*' : 
        result = n2 * n1
    elif opt == '/' : 
        if n1 == 0 : 
            print(f"ERROR: {n2}/0")
            exit()
        result = n2 / n1
    S1.append(int(result))
print(S1[0])