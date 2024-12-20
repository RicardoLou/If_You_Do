N = int(input())
mp = {}
for i in range(0, N) :
    [a, b, c] = input().split()
    mp[b] = [a, c]
M = int(input())
li = input().split()
for i in range(0, len(li)) :
    print(mp[li[i]][0], end=" ")
    print(mp[li[i]][1])
    