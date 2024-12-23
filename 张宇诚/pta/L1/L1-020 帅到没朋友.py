N = int(input())
noHandsome = {}
for i in range(0, N) :
    members = input().split()
    del members[0]
    if(len(set(members)) <= 1 and not members[0] in noHandsome) :
        noHandsome[members[0]] = False
    else :
        for m in members :
            noHandsome[m] = True
input()
m = input().split(" ")
No_one_is_handsome = True
output = ""
for i in m :
    if not i in noHandsome or noHandsome[i] == False:
        noHandsome[i] = True
        output += i + " "
        No_one_is_handsome = False
if(No_one_is_handsome) : print("No one is handsome")
else :
    print(output[:len(output) - 1])