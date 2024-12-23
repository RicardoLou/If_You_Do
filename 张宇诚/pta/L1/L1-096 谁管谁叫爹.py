N = int(input())
for i in range(0, N) :
    a, b = input().split()
    SA = sum([int(ch) for ch in a])
    SB = sum([int(ch) for ch in b])
    if int(a) % SB == 0 and int(b) % SA == 0 or int(a) % SB != 0 and int(b) % SA != 0:
        print(f"{'A' if int(a) > int(b) else 'B'}")
    elif int(a) % SB == 0 :
        print("A")
    else :
        print("B")