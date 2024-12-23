A = []
s = 0
for i in range(0, 3) :
    row = [int(v) for v in input().split()]
    s += sum(row)
    A.append(row)
for row in A :
    if 0 in row :
        row[row.index(0)] = 45 - s
        break
d = {}
for i in range(0, 3) :
    r, c = [int(v) for v in input().split()]
    print(A[r - 1][c - 1])
    
direction = int(input())
s = 0
if direction < 4 :
    s += sum(A[direction - 1])
elif direction < 7 :
    s += sum([A[i][direction - 4] for i in range(0, 3)])
elif direction == 7 :
    s += sum([A[i][i] for i in range(0, 3)])
else :
    s += sum([A[i][2 - i] for i in range(0, 3)])


sum_to_prices = {6 : 10000, 
                 7 : 36,
                 8 : 720,
                 9 : 360, 
                 10 : 80, 
                    11 : 252,
                 12 : 108, 
                 13 : 72, 
                 14 : 54, 
                 15 : 180,
                 16 : 72,
                 17 : 180,
                 18 : 119, 
                 19 : 36,
                 20 : 306,
                 21 : 1080,
                 22 : 144,
                23 : 1800, 
                24 : 3600}
print(sum_to_prices[s])