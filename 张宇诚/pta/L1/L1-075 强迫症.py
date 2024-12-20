a = input()
if len(a) == 6 :
    y = a[:4]
    m = a[4:]
    print(f"{y}-{m}")
else :
    y = a[:2]
    m = a[2:]
    if int(y) < 22 :
        print(20, end="")
    else :
        print(19, end="")
    print(y, end="-")
    print(m)