'''
思路：1.将大于根节点的数和小于根节点的数进行先后递归，记录层数（level），并在后面根据层数排序就可以的到层序遍历
     2.在递归中要计算一个节点序号（nodeid）：根据满二叉树层次遍历的节点序号为0，1，2...顺序排列，
       计算公式为：如果是左结点 nodeid = 2 * 父节点的 nodeid + 1
                 如果是右结点 nodeid = 2 * 父节点的 nodeif + 2
'''
input()
nodes = [int(v) for v in input().split()]
preorder = []

def dfs(nodes, level, nodeId) :
    global preorder, isnot
    if len(nodes) == 0 : return
    root = nodes[0]
    left = []
    right = []
    for i in range(1, len(nodes)) :
        if(nodes[i] > root) : left.append(nodes[i])
        else : right.append(nodes[i])
    preorder.append([level, root, nodeId])
    dfs(left, level + 1, nodeId * 2 + 1)
    dfs(right, level + 1, nodeId * 2 + 2)

dfs(nodes, 0, 0)
level_order = sorted(preorder, key = lambda x : x[0])
for i in range(0, len(level_order)) : 
    print(level_order[i][1], end = "")
    if i != len(level_order) - 1 : 
        print(" ", end = "")
print()

#YES Or NO
ids = [level_order[i][2] for i in range(0, len(level_order))]
for i in range(0, len(ids)) : 
    if ids[i] != i : 
        print("NO")
        exit()

print("YES")