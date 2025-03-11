import math

def iterate(a) : 
    A = [int(v) for v in list(str(a))]
    s = 0
    for i in A : 
        s += i * i
    return s

def isPrime(a) :
    for i in range(2, int(math.sqrt(a)) + 1) : 
        if a % i == 0 : 
            return False
    return True

def getDegree(A) : 
    count = 0
    num = A
    while num != 1 : 
        count += 1
        num = iterate(num)
    if isPrime(A) : return count * 2
    return count

A, B = [int(v) for v in input().split()]

sadness = []
happiness = []
results = []

for i in range(A, B + 1) : 
    num = i
    visited = []
    happy = False
    duli = False
    
    while not num in visited : 
        if num in happiness : 
            happy = True
            if num != i : 
                duli = True
            # 迭代的一个数字在幸福表中出现
            if num in results : 
                # 迭代的一个数字在结果表中出现, 删除
                idx = results.index(num)
                del results[idx]
            break
        if num in sadness : 
            break
        if num == 1 : 
            happy = True
            duli = True
            break
        visited.append(num)
        num = iterate(num)

    if happy : 
        happiness += visited
    else : 
        sadness += visited
    if duli : 
        results.append(i)


if len(results) > 0 : 
    for r in results : 
        print(f"{r} {getDegree(r)}")
else : 
    print("SAD")