ch, N = input().split()
n = int(N)
rows = []
for i in range(0, n) :
    rows.append(input())
buyongdao = True
out = ""
for i in range(n - 1, -1, -1) :
    out += rows[i].replace("@", ch)[::-1]
    out += "\n"
    if rows[i] != rows[n - i - 1] : 
        buyongdao = False

if(buyongdao) :
    print("bu yong dao le")
print(out, end="")