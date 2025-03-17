N, M = [int(v) for v in input().split()]
roads = [[] for v in range(0, N + 1)]
spends = [[] for v in range(0, N + 1)]

for i in range(0, M) : 
    a, b, spend = [int(v) for v in input().split()]
    roads[a].append(b)
    roads[b].append(a)
    spends[a].append(spend)
    spends[b].append(spend)

K = int(input())
minSpend = -1
_id = -1
count = 0

for i in range(0, K) : 
    views = [int(v) for v in input().split()]
    del views[0]
    if views != list(set(views)) or sorted(views) != [v for v in range(1, N + 1)]: continue
    views.insert(0, 0)
    views.append(0)
    spend = 0
    Yes = True
    for j in range(0, len(views) - 1) : 
        if views[j + 1] in roads[views[j]] : 
            spend += spends[views[j]][roads[views[j]].index(views[j + 1])]
        else : 
            Yes = False
            break
    if Yes : 
        count += 1
        if minSpend == -1 or spend < minSpend: 
            minSpend = spend
            _id = i + 1

print(f"{count}\n{_id} {minSpend}")