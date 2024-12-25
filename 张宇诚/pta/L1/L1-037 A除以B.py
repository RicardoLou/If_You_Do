A, B = input().split()
a, b = int(A), int(B)
if b == 0 :
    print(f"{a}/{b}=Error")
elif b < 0 :
    print(f"{a}/({b})={format(a/b, '.2f')}")
else :
    print(f"{a}/{b}={a/b:.2f}")