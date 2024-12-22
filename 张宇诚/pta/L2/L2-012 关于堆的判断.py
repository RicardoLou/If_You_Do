#小顶堆：根节点是所有节点中的最小值（父节点都小于左右子节点）的完全二叉树
N, M = [int(v) for v in input().split()]
heap = []
nums = [int(v) for v in input().split()]
for num in nums :
    heap.append(num)
    index = len(heap) - 1
    while index != 0 :
        parent = (index - 1) // 2
        if heap[parent] > heap[index] :
            heap[parent], heap[index] = heap[index], heap[parent]
            index = parent
        else :
            break
for i in range(0, M) :
    Q = input()
    if Q.find("is the root") != -1 :
        key = int(Q.split()[0])
        if heap[0] == key :
            print("T")
        else :
            print("F")
    elif Q.find("are siblings") != -1 :
        key1 = int(Q.split()[0])
        key2 = int(Q.split()[2])
        key1_index = heap.index(key1)
        key2_index = heap.index(key2)
        max_index = max(key1_index, key2_index)
        min_index = min(key1_index, key2_index)
        if min_index + 1 == max_index and min_index % 2 == 1 :
            print("T")
        else :
            print("F")
    else :
        parent = int(Q.split()[0])
        child = int(Q.split()[-1])
        parent_index = heap.index(parent)
        child_index = heap.index(child)
        if Q.find("is a child of") != -1 :
            parent_index, child_index = child_index, parent_index
        if (child_index - 1) // 2 == parent_index :
            print("T")
        else :
            print("F")