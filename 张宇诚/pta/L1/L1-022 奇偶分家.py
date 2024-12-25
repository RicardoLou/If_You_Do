input()
arr = input().split()
odd = 0
even = 0
for i in arr :
    if int(i) % 2 == 0 :
        even += 1
    else : odd += 1
print(f"{odd} {even}")