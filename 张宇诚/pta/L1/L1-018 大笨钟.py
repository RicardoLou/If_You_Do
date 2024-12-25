time = input()
hh, mm = time.split(":")
h = int(hh)
m = int(mm)
if h >= 0 and h < 12 or h == 12 and m == 0 :
    print(f"Only {time}.  Too early to Dang.")
    exit()
count = 0
if h > 12 :
    count = h - 12
if m > 0 :
    count += 1
print("Dang" * count)