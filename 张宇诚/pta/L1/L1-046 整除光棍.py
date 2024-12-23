x = int(input())
count = 1
while True :
    num = int('1' * count)
    if num % x == 0 :
        print(f"{num // x} {count}")
        break
    count += 1