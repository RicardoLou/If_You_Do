N = int(input())
for i in range(0, N) :
    A, B, C = [int(v) for v in input().split()]
    if A * B == C :
        print("Lv Yan")
    elif A + B == C :
        print("Tu Dou")
    else :
        print("zhe du shi sha ya!")