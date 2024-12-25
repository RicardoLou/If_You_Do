y, n = input().split()
y = int(y)
yy = y
n = int(n)
while True :
    sy = str(yy)
    sy = (4 - len(sy)) * '0' + sy
    if len(set(sy)) == n :
        print(f"{yy - y} {sy}")
        break
    yy += 1