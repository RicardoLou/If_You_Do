N, M, K = [int(v) for v in input().split()]

for i in range(0, K) : 
    lst = [int(v) for v in input().split()]
    need = 1
    stack = []
    Yes = True
    j = 0
    while j < len(lst) : 
        if lst[j] == need : 
            need += 1
            j += 1
            continue
        if len(stack) != 0 and stack[0] == need : 
            del stack[0]
            need += 1
            continue
        if len(stack) != 0 and lst[j] > stack[0] : 
            Yes = False
            break
        stack.insert(0, lst[j])
        if len(stack) > M : 
            Yes = False
            break
        j += 1
    if Yes : print("YES")
    else : print("NO")
        
