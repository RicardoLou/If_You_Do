#状态机

N, M, K = [int(v) for v in input().split()]
pusher = [int(v) for v in input().split()]
box = []
tree = []

def pushTree() : 
    global tree
    for i in range(0, len(tree)) : 
        print(tree[i], end = "")
        if i != len(tree) - 1 : print(" ", end = "")
        else : print()
    tree.clear()

def addLeaf(leaf) : 
    global tree, K
    tree.append(leaf)
    if len(tree) == K : 
        pushTree()
        tree.clear()

#状态
box_state = 0 #盒子空：0 盒子非空未满：1 盒子满：2
pusher_state = 0 #推送器空：0 推送器非空：1
leaf_box_state = 0 #盒子顶的叶子不符合：0 盒子顶的叶子符合：1
leaf_pusher_state = 0 #推送器的叶子不符合：0 推送器的叶子符合：1

    
while len(pusher) != 0 or len(box) != 0 : 
    #状态分配
    if len(box) == 0 : 
        box_state = 0
        leaf_box_state = 0
    else : 
        if len(box) < M : 
            box_state = 1
        else : 
            box_state = 2
        if len(tree) == 0 or box[-1] <= tree[-1] : 
            leaf_box_state = 1
        else : 
            leaf_box_state = 0
            
    if len(pusher) == 0 : 
        pusher_state = 0
        leaf_pusher_state = 0
    else : 
        pusher_state = 1
        if len(tree) == 0 or pusher[0] <= tree[-1] : 
            leaf_pusher_state = 1
        else : 
            leaf_pusher_state = 0

    #状态执行
    if leaf_box_state == 1 : 
        #如果小盒子中最上面的松针满足要求，就取之插好
        addLeaf(box[-1])
        del box[-1]
        continue
    if leaf_pusher_state == 1 : 
        #否则去推送器上取一片
        addLeaf(pusher[0])
        del pusher[0]
        continue
    if leaf_pusher_state == 0 and pusher_state != 0 and box_state != 2 : 
        #如果推送器上拿到的仍然不满足要求，就把拿到的这片堆放到小盒子里
        box.append(pusher[0])
        del pusher[0]
        continue
    if leaf_pusher_state == 0 and pusher_state != 0 and box_state == 2 : 
        #小盒子已经满了，但推送器上取到的松针仍然不满足要求
        pushTree()
        continue
    if leaf_box_state == 0 and box_state != 0 and pusher_state == 0 : 
        #小盒子中最上面的松针不满足要求，但推送器上已经没有松针了。
        pushTree()
        continue

pushTree()