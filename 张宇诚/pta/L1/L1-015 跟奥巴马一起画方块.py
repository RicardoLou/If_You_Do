count, ch = input().split()
count = int(count)
for i in range(0, count // 2 if count % 2 == 0 else (count + 1) // 2) :
    print(ch * count)