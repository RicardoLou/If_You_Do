N = int(input())
degrees = [int(v) for v in input().split()]
degrees.sort()
outgoing, introverted, diff = 0, 0, 0

outgoing = N // 2
introverted = N // 2

if N % 2 != 0 : 
    diff = sum(degrees[:N // 2]) - sum(degrees[N // 2 + 1:])
else : 
    diff = sum(degrees[:N // 2]) - sum(degrees[N // 2:])

if N % 2 != 0 : 
    if diff > 0 : 
        introverted += 1
    else : 
        outgoing += 1
    diff = abs(diff) + degrees[N // 2]
else : 
    diff = abs(diff)

print(f"Outgoing #: {outgoing}")
print(f"Introverted #: {introverted}")
print(f"Diff = {diff}")
