N = int(input())
postorder = input().split()
inorder = input().split()
postorder = postorder[::-1]
cur_index = 0
stack = []

def func(inorder, layout) :
    global cur_index, postorder, N, stack
    if cur_index >= N :
        return
    cur_node = postorder[cur_index]
    if not cur_node in inorder :
        return
    left = []
    right = []
    k = 0
    for i in range(0, len(inorder)) :
        if inorder[i] == cur_node :
            k = i + 1
            break
        left.append(inorder[i])
    for j in range(k, len(inorder)) :
        right.append(inorder[j])
    cur_index += 1
    func(right, layout + 1)
    func(left, layout + 1)
    stack.append([cur_node, layout])

func(inorder, 0)
preorder = stack[::-1]
levelorder = sorted(preorder, key = lambda x : x[1])

for i in range(0, len(levelorder)) :
    print(levelorder[i][0], end="")
    if i != len(levelorder) - 1 :
        print(" ", end = "")
print()