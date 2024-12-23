N = int(input())
caps = input().split()
K = int(input())
for i in range(0, K) :
    chooses = input().split()
    right = False
    fail = False
    for i in range(0, len(chooses)) :
        if chooses[i] == '0' :
            continue
        if chooses[i] == caps[i] :
            right = True
        else :
            fail = True
            break
    if fail or not right :
        print("Ai Ya")
    else :
        print("Da Jiang!!!")