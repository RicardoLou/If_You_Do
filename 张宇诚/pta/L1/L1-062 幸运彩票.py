N = int(input())
for i in range(0, N) :
    num = input()
    front = num[:3]
    back = num[3:6]
    front_sum = sum([int(v) for v in front])
    back_sum = sum([int(v) for v in back])
    if(front_sum == back_sum) :
        print("You are lucky!")
    else :
        print("Wish you good luck.")