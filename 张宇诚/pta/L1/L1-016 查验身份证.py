weights = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
z_to_m = {0 : '1', 1 : '0', 2 : 'X', 3 : '9', 4 : '8', 5 : '7', 
          6 : '6', 7 : '5', 8 : '4', 9 : '3', 10 : '2'}
N = int(input())
Allpassed = True
for i in range(0, N) :
    num = input()
    s = 0
    d = 0
    for j in range(0, len(num) - 1) :
        if num[j].isdigit() :
            s += int(num[j]) * weights[j]
            z = s % 11
            m = z_to_m[z]
        else : 
            d = 1
            Allpassed = False
            print(num)
            break
    if m != num[len(num) - 1] and d == 0 :
        Allpassed = False
        print(num)

if Allpassed : 
    print("All passed")