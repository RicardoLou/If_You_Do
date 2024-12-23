[count, ch] = input().split(" ")

c = int(count)
count = (int(count) - 1) / 2
d = 0
a = 1
while True :
    count -= a + 2
    if count >= 0 : a += 2
    else : break

for i in range(a, 1, -2) :
    print(" " * ((a - i) // 2), end = "")
    print(ch * i)
    d += i

for i in range(1, a+2, 2) :
    print(" " * ((a - i) // 2), end = "")
    print(ch * i)
    d += i

print(c - d, end="")
    