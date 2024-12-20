w, h = [float(v) for v in input().split()]
print(f"{w / pow(h, 2):.1f}")
if w / pow(h, 2) > 25 :
    print("PANG")
else :
    print("Hai Xing")