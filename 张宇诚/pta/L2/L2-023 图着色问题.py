V, E, K = [int(v) for v in input().split()]
edges = [[] for i in range(0, V + 1)]

for i in range(0, E) : 
    v1, v2 = [int(v) for v in input().split()]
    edges[v1].append(v2)
    edges[v2].append(v1)

N = int(input())
for i in range(0, N) : 
    colors = [int(v) for v in input().split()]
    if len(set(colors)) != K : 
        print("No")
        continue
    isBreak = False
    for i in range(0, len(colors) - 1) : 
        for j in range(i + 1, len(colors)) : 
            if colors[i] == colors[j] : 
                v1 = i + 1
                v2 = j + 1
                if v1 in edges[v2] : 
                    print("No")
                    isBreak = True
                    break
        if isBreak : break
    if not isBreak : 
        print("Yes")
                    