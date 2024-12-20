N, M = [int(v) for v in input().split()]
curQus = ""
for i in range(0, N) :
    qus = input()
    if qus.find("qiandao") != -1 or qus.find("easy") != -1 :
        continue
    M -= 1
    if M < 0 :
        curQus = qus
        break
if M >= 0 :
    print("Wo AK le")
else :
    print(curQus)