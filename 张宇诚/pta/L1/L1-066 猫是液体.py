import functools as ft
print(ft.reduce(lambda a, b : a * b, [int(v) for v in input().split()]))