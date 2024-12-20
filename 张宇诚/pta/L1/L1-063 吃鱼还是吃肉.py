N = int(input())
for i in range(0, N) :
    sex, height, weight = input().split()
    height = int(height)
    weight = int(weight)
    normal_height = 0
    normal_weight = 0
    if sex == '0' :
        normal_height = 129
        normal_weight = 25
    else :
        normal_height = 130
        normal_weight = 27
        
    if height < normal_height :
        print("duo chi yu! ", end="")
    elif height > normal_height :
        print("ni li hai! ", end="")
    else :
        print("wan mei! ", end="")
        
    if weight < normal_weight :
        print("duo chi rou!")
    elif weight > normal_weight :
        print("shao chi rou!")
    else :
        print("wan mei!")