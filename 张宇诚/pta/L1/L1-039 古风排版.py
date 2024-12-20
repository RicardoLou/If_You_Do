N = int(input())
S = input()
str_list = []
s = ""
for i in range(0, len(S)) :
    s += S[i]
    if i % N == N - 1 :
        str_list.append(s)
        s = ""
if s != "":
    str_list.append(s + " " * (N - len(s)))
for i in range(0, N) :
    for s in reversed(str_list) :
        print(s[i], end="")
    print()