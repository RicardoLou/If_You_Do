N = int(input())
words = []
for i in range(0, N) :
    words.append(input())
k = int(input())
s = input()
count = 0

for i in range(0, N) :
    count += s.count(words[i])
    s = s.replace(words[i], "________")
if(count >= k) :
    print(count)
    print("He Xie Ni Quan Jia!")
else :
    for i in range(0, N) :
        s = s.replace(words[i], "________")
    s = s.replace("________", "<censored>")
    print(s)