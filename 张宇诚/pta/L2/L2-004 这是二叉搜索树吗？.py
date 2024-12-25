N = int(input())
preorder = [int(v) for v in input().split()]

#判断是否为镜像 如果即不是不是镜像也不是镜像就是NO
def isMirror(preorder, mirror) :
    if len(preorder) == 0 :
        return True
    left = []
    right = []
    k = 0
    for i in range(1, len(preorder)) :
        if preorder[i] >= preorder[0] if mirror else preorder[i] < preorder[0] :
            left.append(preorder[i])
        else :
            k = i
            break
    if k != 0 :
        for i in range(k, len(preorder)) :
            if preorder[i] >= preorder[0] if mirror else preorder[i] < preorder[0] :
                return False
            right.append(preorder[i])
    return isMirror(left, mirror) * isMirror(right, mirror)
    
postorder = []

def getPostorder(preorder, mirror) :
    global postorder
    if len(preorder) == 0 :
        return
    left = []
    right = []
    k = 0
    for i in range(1, len(preorder)) :
        if preorder[i] >= preorder[0] if mirror else preorder[i] < preorder[0] :
            left.append(preorder[i])
        else :
            k = i
            break
    if k != 0 :
        for i in range(k, len(preorder)) :
            right.append(preorder[i])
    getPostorder(left, mirror)
    getPostorder(right, mirror)
    postorder.append(preorder[0])

mirrored = isMirror(preorder, True)
not_mirrored = isMirror(preorder, False)

if not mirrored and not not_mirrored :
    print("NO")
    exit()

getPostorder(preorder, mirrored)

print("YES")
for i in range(0, len(postorder)) :
    print(postorder[i], end="")
    if i != len(postorder) - 1 :
        print(" ", end="")
print()