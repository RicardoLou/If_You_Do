N, G, K = [int(v) for v in input().split()]

lst = []

money = 0

for i in range(0, N) : 
    email, score = input().split()
    score = int(score)
    lst.append([score, email])
    if score >= G and score <= 100 : 
        money += 50
    elif score >= 60 and score < G : 
        money += 20

lst.sort(key = lambda x:(-x[0], x[1]))

print(money)
frontRack = 0
for i in range(0, len(lst)) : 
    score, email = lst[i]
    rack = 0
    if i == 0 : 
        rack = 1
    elif score == lst[i - 1][0]: 
        rack = frontRack
    else : 
        rack = i + 1
    if rack > K : break
    print(f"{rack} {email} {score}")
    frontRack = rack