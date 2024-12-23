num = input()
m = 1.0
length = len(num)
if num[0] == '-' : 
    m += 0.5
    length -= 1
if int(num) % 2 == 0 :
    m *= 2
count = num.count('2')
print(format(count / length * m * 100, ".2f"), end="")
print("%")