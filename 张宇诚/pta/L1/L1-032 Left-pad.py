count, ch = input().split()
count = int(count)
s = input()
newS = ""
for i in range(len(s) - 1, -1, -1) :
    if count > 0 :
        newS = s[i] + newS
        count -= 1

newS = ch * count + newS
print(newS)