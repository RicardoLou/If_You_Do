a, b, c = input().split()
a = float(a)
c = float(c)
d = a * (2.455 if b == '0' else 1.26)
print(f"{d:.2f}", end=" ")
if d < c :
    print("^_^")
else :
    print("T_T")