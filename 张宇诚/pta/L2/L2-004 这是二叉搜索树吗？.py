
input()
preorder = [int(v) for v in input().split()]
sign = -1
postorder = []

def func(preorder) : 
    global sign
    if len(preorder) == 0 : 
        return
    
    root = preorder[0]
    left = []
    right = []
    
    mirro = False
    if len(preorder) > 1 : 
        mirro = preorder[1] >= root
        
    i = 1
    while i < len(preorder) : 
        s = preorder[i] < root
        if mirro : 
            s = not s
        if s : 
            left.append(preorder[i])
        else : 
            break
        i += 1
    j = i
    while j < len(preorder) : 
        s = preorder[j] >= root
        if mirro : 
            s = not s
        if s : 
            right.append(preorder[j])
        else : 
            break
        j += 1

    if j != len(preorder) : 
        print("NO")
        exit()
    if len(left) != 0 and len(right) != 0 : 
        if sign != -1 and sign != mirro : 
            print("NO")
            exit()
        else : 
            sign = mirro
    
    func(left)
    func(right)
    postorder.append(root)

func(preorder)
print("YES")
print(" ".join([str(v) for v in postorder]))