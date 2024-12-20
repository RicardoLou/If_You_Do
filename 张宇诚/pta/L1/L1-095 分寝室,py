n0, n1, n = [int(v) for v in input().split()]
count = 1
diff = 0
women, man = 0, 0
mindiff = 1000000
while count < n :
    count2 = n - count
    if n0 % count == 0 and n1 % count2 == 0 and n0 / count > 1 and n1 / count2 > 1 :
        if abs(n0 / count - n1 / count2) < mindiff :
            women = count
            man = count2
            mindiff = abs(n0 / count - n1 / count2)
    count += 1
if women != 0 or man != 0 :
    print(f"{women} {man}")
else :
    print("No Solution")