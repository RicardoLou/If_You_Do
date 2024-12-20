dire = {0: "ling",
1: "yi",
2: "er",
3: "san",
4: "si",
5: "wu",
6: "liu",
7: "qi",
8: "ba",
9: "jiu"}

b = input()

for i in range(0, len(b)) :
    if b[i] == '-' : print("fu", end="")
    else : print(dire[int(b[i])], end="")
    if(i == len(b) - 1) : print()
    else : print("", end=" ")