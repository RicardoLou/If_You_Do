N = int(input())
lst = [[0, 0, i + 1] for i in range(N)]
for i in range(0, N) :
    record = [int(v) for v in input().split()]
    for j in range(1, len(record), 2) :
        Id = record[j]
        money = record[j + 1]
        lst[i][0] -= money
        lst[Id - 1][0] += money
        lst[Id - 1][1] += 1
lst.sort(key = lambda x : (-x[0], -x[1]))

for member in lst :
    print(f"{member[2]} {member[0] * 0.01:.2f}")