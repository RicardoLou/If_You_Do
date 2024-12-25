N = int(input())
dt = {}
for i in range(0, N) :
    nums = [int(v) for v in input().split()]
    nums.pop(0)
    for j in nums :
        if j in dt.keys() :
            dt[j] += 1
        else :
            dt[j] = 1
a = sorted(dt.items())

max_count = 0
max_num = 0
for i in a :
    if i[1] >= max_count :
        max_num = i[0]
        max_count = i[1]
print(f"{max_num} {max_count}")