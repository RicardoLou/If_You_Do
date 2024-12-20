x, y = [int(v) for v in input().split()]
print(100 * 100 // 2 - (x) * (y) // 2 - (100 - x) * (100 - y) // 2 - (100 - x) * (y))