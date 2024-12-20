ss = []
for j in range(0, 2) :
    s = ""
    a = input()
    for i in range(1, len(a)) :
      if int(a[i]) % 2 == int(a[i-1]) % 2 :
        s += max([a[i], a[i-1]])
    ss.append(s)
print(ss[0])
if len(set(ss)) != 1 :
    print(ss[1])