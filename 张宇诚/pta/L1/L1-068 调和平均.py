N = int(input())
nums = [float(v) for v in input().split()]
avg = 0.0
for i in nums :
    avg += 1 / i
avg /= N
avg = 1 / avg
print(f"{avg:.2f}")