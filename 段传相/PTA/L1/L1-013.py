n, sum, jc = int(input()), 1, 1
for i in range(2, n + 1, 1) :
    jc *= i
    sum += jc
    print(sum)