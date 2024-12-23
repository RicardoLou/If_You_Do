A, B = [int(v) for v in input().split()]
A2, B2 = A, B
count = int(input())
for i in range(0, count) :
    Asay, Ahand, Bsay, Bhand = [int(v) for v in input().split()]
    if Asay + Bsay == Ahand and Asay + Bsay == Bhand :
        pass
    elif Asay + Bsay == Ahand :
        A -= 1
        if A < 0 :
            print("A")
            print(B2 - B)
            exit()
    elif Asay + Bsay == Bhand :
        B -= 1
        if B < 0 :
            print("B")
            print(A2 - A)
            exit()