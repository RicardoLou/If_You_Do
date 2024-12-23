count = 0
A, B = "", ""
while True :
    name = input()
    if name == '.' : break;
    count += 1
    if count == 2 :
        A = name
    elif count == 14 :
        B = name

if A == "" and B == "" :
    print("Momo... No one is for you ...")
elif B == "" :
    print(f"{A} is the only one for you...")
else :
    print(f"{A} and {B} are inviting you to dinner...")