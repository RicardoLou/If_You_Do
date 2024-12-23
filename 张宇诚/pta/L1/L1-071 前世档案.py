N, M = [int(v) for v in input().split()]
count = pow(2, N)
for i in range(0, M) :
    lst = range(1, count + 1)
    answer = input()
    for j in answer :
        if j == 'y' :
            lst = lst[:len(lst) // 2]
        else :
            lst = lst[len(lst) // 2 : len(lst)]
    print(lst[0])
        