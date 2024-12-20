first = 0
row = 0
count = 0
while True :
    msg = input()
    if msg == '.' :
        break
    row += 1
    if msg.find("chi1 huo3 guo1") != -1 :
        if first == 0 :
            first = row
        count += 1
print(row)
if count == 0 :
    print("-_-#")
else :
    print(f"{first} {count}")