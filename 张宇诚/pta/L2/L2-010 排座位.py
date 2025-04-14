N, M, K = [int(v) for v in input().split()]
friends = [set() for i in range(N + 1)]
enemies = [set() for i in range(N + 1)]

for i in range(0, M) :
    a, b, r = [int(v) for v in input().split()]
    if r == 1 :
        friends[a].add(b)
        friends[b].add(a)
    else :
        enemies[a].add(b)
        enemies[b].add(a)

def isFriend(a, b) : 
    queue = [a]
    visitied = {a}
    while len(queue) != 0 : 
        if queue[0] in friends[b] : 
            return True;
        for f in friends[queue[0]] : 
            if f in visitied : 
                continue
            queue.append(f)
            visitied.add(f)
        del queue[0]
    return False

for i in range(0, K) : 
    a, b = [int(v) for v in input().split()]
    friend = isFriend(a, b)
    enemy = False
    if a in enemies[b] or b in enemies[a] : 
        enemy = True
    if not enemy and friend : 
        print("No problem")
        continue
    if not enemy and not friend : 
        print("OK")
        continue
    if enemy and friend : 
        print("OK but...")
        continue
    if enemy : 
        print("No way")
        