N = int(input())
for i in range(0, N) :
    H, W = input().split()
    h = int(H)
    w = int(W) / 2
    normalWeight = (h - 100) * 0.9
    if abs(w - normalWeight) < normalWeight * 0.1 :
        print("You are wan mei!")
    elif w - normalWeight > 0 :
        print("You are tai pang le!")
    else :
        print("You are tai shou le!")