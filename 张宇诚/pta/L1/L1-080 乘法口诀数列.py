a1, a2, n = [int(v) for v in input().split()]
count = 2
a = 0
lst = [a1, a2]
while True :
    num = lst[a] * lst[a + 1]
    a += 1
    for digit in str(num) :
        lst.append(int(digit))
        if len(lst) >= n :
            for i in range(0, n) :
                print(lst[i], end="")
                if i != n - 1 :
                    print(" ", end="")
            exit()