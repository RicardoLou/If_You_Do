a, b = [int(v) for v in input().split()]
Sum = 0
count = b - a
for i in range(b - a + 1) :
    if i % 5 == 0 and i != 0 : print()
    print(str(a).rjust(5), end="")
    Sum += a
    a += 1
print()
print("Sum = ",end="")
print(Sum)