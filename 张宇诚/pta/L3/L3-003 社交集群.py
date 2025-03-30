# 1 2 3 4 5      6 7 8    65

N = int(input())
crowds = []

for i in range(0, N) : 
    likes = [int(v) for v in input().split()[1:]]
    lst = []
    for j in range(0, len(crowds)) : 
        for like in likes : 
            if like in crowds[j][0] : 
                lst.append(j)
    if len(lst) == 0 : 
        crowds.append([likes, 1])
    else : 
        for j in range(len(lst) - 1, 0, -1) : 
            crowds[lst[0]][0] += crowds[lst[j]][0]
            crowds[lst[0]][1] += crowds[lst[j]][1]
            del crowds[lst[j]]
        crowds[lst[0]][0] = list(set(crowds[lst[0]][0] + likes))
        crowds[lst[0]][1] += 1

print(len(crowds))
print(" ".join(str(v) for v in sorted([crowds[u][1] for u in range(0, len(crowds))], reverse = True)))
