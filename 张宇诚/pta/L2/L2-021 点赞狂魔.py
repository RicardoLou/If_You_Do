N = int(input())
infos = []

for i in range(0, N) : 
    lst = input().split()
    name = lst[0]
    likes = [lst[j] for j in range(2, len(lst))]
    like_count = len(likes)
    diff_count = len(set(likes))
    infos.append([name, diff_count, like_count])

infos.sort(key = lambda x:(-x[1], x[2]))

for i in range(0, len(infos)) : 
    if i >= 3 : break
    print(infos[i][0], end = "")
    if i != 2 and i != len(infos) - 1 : 
        print(" ", end="")

if len(infos) < 3 : 
    for i in range(0, 3 - len(infos)) : 
        print(" -", end="")