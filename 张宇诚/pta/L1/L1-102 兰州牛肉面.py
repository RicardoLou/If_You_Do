N = int(input())
prices = input().split(" ")
counts = []
for i in range(0, 1000):
    counts.append(0)
while True :
    [id, count] = input().split(" ")
    id = int(id)
    count = int(count)
    if id == 0:
        break
    else :
        counts[id - 1] += count
sum = 0.0
for i in range(0, N) :
    print(counts[i])
    sum += counts[i] * float(prices[i])
print(format(sum, ".2f"))