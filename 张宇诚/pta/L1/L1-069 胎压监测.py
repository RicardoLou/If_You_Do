a = [int(v) for v in input().split()]
min_warning = a[4]
diff_value = a[5]
max_value = max(a[:4])
count = 0
t = 0
for i in range(0, 4) :
    diff = max_value - a[i]
    if a[i] < min_warning or diff > diff_value:
        count += 1
        t = i + 1
if count >= 2 :
    print("Warning: please check all the tires!")
elif count == 1 :
    print(f"Warning: please check #{t}!")
else :
    print("Normal")