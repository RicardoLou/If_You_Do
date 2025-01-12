N = int(input())
parents = [int(v) for v in input().split()]
childs = [[] for v in range(0, N + 1)]
for i in range(0, len(parents)) :
    parent = parents[i]
    if parent == -1 :
        childs[0].append(i + 1)
    else :
        childs[parent].append(i + 1)

min_beifen = 0
queue = childs[0]
youngest = []

while len(queue) != 0 :
    youngest.clear()
    youngest += queue
    newQueue = []
    for child in queue :
        newQueue += childs[child];
    queue = newQueue.copy()
    min_beifen += 1
print(min_beifen)
for i in range(0, len(youngest)) :
    print(youngest[i], end = "")
    if i != len(youngest) - 1 :
        print(" ", end = "")
