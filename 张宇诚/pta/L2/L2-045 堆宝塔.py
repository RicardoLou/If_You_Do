
N = int(input())

nums = [int(v) for v in input().split()]

A = [nums[0]]
B = []

del nums[0]

count = 0
highest = 0

while len(nums) != 0 : 
    if nums[0] < A[-1] : 
        A.append(nums[0])
        del nums[0]
    elif len(B) == 0 or nums[0] > B[-1] : 
        B.append(nums[0])
        del nums[0]
    else : 
        count += 1
        if len(A) > highest : 
            highest = len(A)
        A.clear()
        while len(B) != 0 and B[-1] > nums[0] : 
            A.append(B.pop())
        A.append(nums[0])
        del nums[0]
        
if len(A) != 0 : 
    count += 1
    if len(A) > highest : 
        highest = len(A)

if len(B) != 0 : 
    count += 1
    if len(B) > highest : 
        highest = len(B)

print(f"{count} {highest}")
