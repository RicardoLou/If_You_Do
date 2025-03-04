N = int(input())
nodes = [int(v) for v in input().split()]
M = int(input())

levels = {}
parents = {}
directs = {} #left:0 right:1

#----------def begin----------
def dfs(nodes, level, parent, direct) : 
    global levels, parents, directs
    if len(nodes) == 0 : return
    root = nodes[0]
    left, right = [], []
    for i in range(1, len(nodes)) : 
        if nodes[i] < root : 
            left.append(nodes[i])
        else : right.append(nodes[i])
    levels[root] = level
    parents[root] = parent
    directs[root] = direct
    dfs(left, level + 1, root, 0)
    dfs(right, level + 1, root, 1)

def isInNodes(A) : 
    if A in nodes : 
        return True
    print("No")
    return False

def isRoot(A) : 
    global levels
    if levels[A] == 0 : 
        print("Yes")
    else : print("No")
    
def isSiblings(A, B) : 
    global parents
    if parents[A] == parents[B] : 
        print("Yes")
    else : print("No")

def isParent(A, B) : 
    global parents
    if A == parents[B] : 
        print("Yes")
    else : print("No")

def isLeftChild(A, B) : 
    global parents, directs
    if B == parents[A] and directs[A] == 0 : 
        print("Yes")
    else : print("No")
    
def isRightChild(A, B) : 
    global parents, directs
    if B == parents[A] and directs[A] == 1 : 
        print("Yes")
    else : print("No")

def isSameLevel(A, B) : 
    global levels
    if levels[A] == levels[B] : 
        print("Yes")
    else : print("No")
#----------def end----------

dfs(nodes, 0, -1, 1)
for i in range(0, M) : 
    Q = input().split()
    if "root" in Q : 
        #A is the root
        A = int(Q[0])
        if isInNodes(A) : 
            isRoot(A)
    elif "siblings" in Q : 
        #A and B are siblings
        A = int(Q[0])
        B = int(Q[2])
        if isInNodes(A) and isInNodes(B) : 
            isSiblings(A, B)
    elif "parent" in Q : 
        #A is the parent of B
        A = int(Q[0])
        B = int(Q[-1])
        if isInNodes(A) and isInNodes(B) : 
            isParent(A, B)
    elif "left" in Q : 
        #A is the left child of B
        A = int(Q[0])
        B = int(Q[-1])
        if isInNodes(A) and isInNodes(B) : 
            isLeftChild(A, B)
    elif "right" in Q : 
        #A is the right child of B
        A = int(Q[0])
        B = int(Q[-1])
        if isInNodes(A) and isInNodes(B) : 
            isRightChild(A, B)
    elif "same" in Q : 
        #A and B are on the same level
        A = int(Q[0])
        B = int(Q[2])
        if isInNodes(A) and isInNodes(B) : 
            isSameLevel(A, B)
    else : 
        print("error(Debug)")