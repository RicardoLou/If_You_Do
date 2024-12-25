a, b, c = [int(v) for v in input().split()]
if a > b : 
    a, b  = b, a
if a > c :
    a, c = c, a
if b > c :
    b, c = c, b
print(str(a) + "->" + str(b) + "->" + str(c))