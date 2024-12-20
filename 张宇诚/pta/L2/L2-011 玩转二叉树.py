N = int(input())
inorder = input().split()
preorder = input().split()

cur_index = 0

queue = []

def func(inorder, layout) :
    global N, preorder, cur_index, queue
    if cur_index >= N :
        return
    cur_node = preorder[cur_index]
    if not cur_node in inorder :
        return
    left = []
    right = []
    k = 0
    for i in range(0, len(inorder)) :
        if inorder[i] == cur_node :
            k = i + 1
            break;
        left.append(inorder[i])
    for j in range(k, len(inorder)) :
        right.append(inorder[j])
    queue.append([cur_node, layout])
    cur_index += 1
    func(left, layout + 1)
    func(right, layout + 1)

func(inorder, 0)
reverse = sorted(queue[::-1], key=lambda x : x[1])
for i in range(0, N) :
    print(reverse[i][0], end="")
    if i != N - 1 :
        print(" ", end="")
print()