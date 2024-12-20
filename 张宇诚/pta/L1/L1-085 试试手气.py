upper = [int(v) for v in input().split()]
n = int(input())
for i in range(0, 6) :
    up = upper[i]
    size = 7
    size -= n
    if size <= up :
        size -= 1
    print(size, end="")
    if i != 5 :
        print(" ", end="")
print()