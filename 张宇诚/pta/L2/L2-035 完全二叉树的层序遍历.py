#根据节点数求完全二叉树层数
def getLevelCount(N) : 
    # n 层完美二叉树有 2^n-1 个节点
    n = 1
    while pow(2, n) - 1 < N : 
        n += 1
    return n

N = int(input())
nodes = input().split()

nodes.reverse()
levelOrder = [[] for i in range(0, getLevelCount(N))]
curIndex = 0

def dfs(level, _id) : 
    global nodes, curIndex, levelOrder
    if curIndex >= len(nodes) or _id > len(nodes) : 
        return
    node = nodes[curIndex]
    levelOrder[level].append(node)
    curIndex += 1
    dfs(level + 1, _id * 2 + 1)
    dfs(level + 1, _id * 2)

dfs(0, 1)
out = ""

for level in levelOrder : 
    for node in level[::-1] : 
        out += node + " "

print(out[:len(out) - 1])