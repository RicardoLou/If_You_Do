#坑: -0

N, M = [int(v) for v in input().split()]
photos = []

for i in range(0, M) : 
    photo = input().split()
    del photo[0]
    photos.append(photo)

def getClosest(A) : 
    global photos, N
    degrees = [0 for i in range(0, N)]
    for photo in photos : 
        if not A in photo : 
            continue
        for friend in photo : 
            if not (friend[0] == '-' and A[0] == '-' or friend[0] != '-' and A[0] != '-') : 
                degrees[abs(int(friend))] += 1 / len(photo)
    maxValue = max(degrees)
    Closest = []
    for i in range(0, len(degrees)) : 
        if degrees[i] == maxValue : 
            if A[0] == '-' : Closest.append(str(i))
            else : Closest.append('-' + str(i))
    return Closest
    
A, B = input().split()
AClosest = getClosest(A)
BClosest = getClosest(B)

if B in AClosest and A in BClosest : 
    print(f"{A} {B}")
else : 
    for a in AClosest : 
        print(f"{A} {a}")
    for b in BClosest : 
        print(f"{B} {b}")