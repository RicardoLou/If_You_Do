#Dijkstra 全部通过   DFS超时
INF = 1000000000
N, M = [int(v) for v in input().split()]
Dist = [[INF for i in range(0, N)] for j in range(0, N)]
Time = [[INF for i in range(0, N)] for j in range(0, N)]

for i in range(0, M) : 
    V1, V2, one_way, length, time = [int(v) for v in input().split()]
    Dist[V1][V2] = length
    Time[V1][V2] = time
    if one_way == 0 : 
        Dist[V2][V1] = length
        Time[V2][V1] = time

S, D = [int(v) for v in input().split()]
        
def dijkstra_minTime() : 
    vis = [False for i in range(0, N)]
    min_time = [INF for i in range(0, N)]
    parent = [-1 for i in range(0, N)]
    dis = [INF for i in range(0, N)]
    min_time[S] = 0
    dis[S] = 0

    for i in range(1, N) : 
        t = -1
        for j in range(0, N) : 
            if (not vis[j] and (t == -1 or min_time[j] < min_time[t])) : 
                t = j
        vis[t] = True
        for j in range(0, N) : 
            time = min_time[t] + Time[t][j]
            distance = dis[t] + Dist[t][j]
            if time < min_time[j] : 
                min_time[j] = time
                dis[j] = distance
                parent[j] = t
            elif time == min_time[j] and distance < dis[j] : 
                dis[j] = distance
                parent[j] = t
    node = D
    path = []
    while node != -1 : 
        path.append(node)
        node = parent[node]
    return [min_time[D], path[::-1]]

def dijkstra_minDist() : 
    vis = [False for i in range(0, N)]
    parent = [-1 for i in range(0, N)]
    dis = [INF for i in range(0, N)]
    length = [0 for i in range(0, N)]
    dis[S] = 0

    for i in range(1, N) : 
        t = -1
        for j in range(0, N) : 
            if (not vis[j] and (t == -1 or dis[j] < dis[t])) : 
                t = j
        vis[t] = True
        for j in range(0, N) : 
            distance = dis[t] + Dist[t][j]
            if distance < dis[j] : 
                dis[j] = distance
                length[j] = length[t] + 1
                parent[j] = t
            elif distance == dis[j] and length[t] + 1 < length[j] : 
                length[j] = length[t] + 1
                parent[j] = t
    node = D
    path = []
    while node != -1 : 
        path.append(node)
        node = parent[node]
    return [dis[D], path[::-1]]

minTimeResult = dijkstra_minTime()
minDistResult = dijkstra_minDist()
if minTimeResult[1] == minDistResult[1] : 
    print(f"Time = {minTimeResult[0]}; Distance = {minDistResult[0]}: " + " => ".join([str(v) for v in minTimeResult[1]]))
else : 
    print(f"Time = {minTimeResult[0]}: " + " => ".join([str(v) for v in minTimeResult[1]]))
    print(f"Distance = {minDistResult[0]}: " + " => ".join([str(v) for v in minDistResult[1]]))
    



'''
N, M = [int(v) for v in input().split()]
roads = [[] for i in range(0, N)]

for i in range(0, M) : 
    V1, V2, one_way, length, time = [int(v) for v in input().split()]
    roads[V1].append([V2, length, time])
    if one_way == 0 : 
        roads[V2].append([V1, length, time])

visited = set()
minLenghtRoads = []
minTimeRoads = []
minLenght = -1
minTime = -1
minTimeMinLen = -1
        
def dfs(begin, end, result, length, time) : 
    global minLenght, minTime, minTimeMinLen, minTimeRoads, minLenghtRoads, visited
    if begin == end : 
        if minLenght == -1 or length < minLenght or length == minLenght and len(result) < len(minLenghtRoads) : 
            minLenght = length
            minLenghtRoads = result.copy()
        if minTime == -1 or time < minTime or time == minTime and length < minTimeMinLen : 
            minTime = time
            minTimeMinLen = length
            minTimeRoads = result.copy()
        return
    if minLenght != -1 and length >= minLenght : 
        return
    for idx, l, t in roads[begin] : 
        if idx in visited : 
            continue
        visited.add(idx)
        result.append(idx)
        dfs(idx, end, result, length + l, time + t)
        result.pop()
        visited.remove(idx)

begin, end = [int(v) for v in input().split()]
dfs(begin, end, [], 0, 0)
if minTimeRoads == minLenghtRoads : 
    print(f"Time = {minTime}; Distance = {minLenght}: {begin} => " + " => ".join([str(v) for v in minLenghtRoads]))
else : 
    print(f"Time = {minTime}: {begin} => " + " => ".join([str(v) for v in minTimeRoads]))
    print(f"Distance = {minLenght}: {begin} => " + " => ".join([str(v) for v in minLenghtRoads]))
'''