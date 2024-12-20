s = input()
n = int(s.split()[0])
c = int(s.split()[1])
sum_skills = 0
arr = input().split()
for i in range(0, c):
    sum_skills += int(arr[i])
avg = int(sum_skills / n)
mod = sum_skills % n
if(c-avg == 0) : print(n)
elif(avg == 0) : print(0)
else : print(int(mod / (c - avg)))