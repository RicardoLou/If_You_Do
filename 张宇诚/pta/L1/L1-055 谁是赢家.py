a, b = [int(v) for v in input().split()]
p = input().split()

if a > b and p.count("0") >= 1 or p.count("0") == 3:
    print(f"The winner is a: {a} + {p.count('0')}")
else :
    print(f"The winner is b: {b} + {p.count('1')}")