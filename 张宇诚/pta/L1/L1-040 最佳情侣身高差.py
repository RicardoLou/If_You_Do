N = int(input())
for i in range(0, N) :
    sex, height = input().split()
    height = float(height)
    if sex == 'M' :
        print(format(height / 1.09, ".2f"))
    else :
        print(format(height * 1.09, ".2f"))