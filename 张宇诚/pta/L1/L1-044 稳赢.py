K = int(input())
count = 0
while True :
    a = input()
    if a == "End" :
        break
    count += 1
    if count % (K + 1) == 0 :
        print(a)
    elif a == "ChuiZi" :
        print("Bu")
    elif a == "JianDao":
        print("ChuiZi")
    else :
        print("JianDao")