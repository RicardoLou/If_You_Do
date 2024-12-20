a = sum([int(v) for v in input().split()])

def func(a) :
    if a == 1 :
        return a
    return a * func(a - 1)

print(func(a))