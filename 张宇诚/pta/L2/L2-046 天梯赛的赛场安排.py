import math

N, C = [int(v) for v in input().split()]

count = 0
courts = []
numbers = []

for i in range(0, N) : 
    sch, number = input().split()
    number = int(number)
    print(f"{sch} {math.ceil(number / C)}")
    numbers.append(number)

numbers.sort(reverse = True)

def insert(num, lst) : 
    left = 0
    right = len(lst)
    while left <= right : 
        mid = (left + right) // 2
        if lst[mid] > num : 
            left = mid
            if mid == len(lst) - 1 or lst[mid + 1] <= num : 
                lst.insert(mid + 1, num)
                return
        elif lst[mid] < num : 
            right = mid
            if lst[mid - 1] >= num : 
                lst.insert(mid, num)
                return
        else : 
            lst.insert(mid, num)
            return
        
while len(numbers) != 0 : 
    maxNum = numbers[0]
    if maxNum // C > 0 : 
        count += 1
        newNum = maxNum - C
        if newNum != 0 : 
            insert(newNum, numbers)
    else : 
        sign = True
        d = maxNum % C
        for i in range(0, len(courts)) : 
            if courts[i] + d < C : 
                courts[i] += d
                sign = False
                break
            elif courts[i] + d == C : 
                del courts[i]
                sign = False
                break
        if sign : 
            count += 1
            courts.append(d)
    del numbers[0]
    
    
print(count)