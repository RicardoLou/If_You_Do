N = int(input())
lst = []
for i in range(0, N) :
    name, num = input().split()
    lst.append([name, int(num)])
avg = 0
for item in lst :
    avg += item[1]
avg /= len(lst)
avg /= 2

minimum = 100000
winner = ""
for item in lst :
    if abs(item[1] - avg) < minimum :
        minimum = abs(item[1] - avg)
        winner = item[0]

print(f"{int(avg)} {winner}")