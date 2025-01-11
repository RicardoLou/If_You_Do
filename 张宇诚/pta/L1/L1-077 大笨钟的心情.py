happy = [int(v) for v in input().split()]
while True :
    hour = int(input())
    if hour < 0 or hour > 23 :
        break
    print(f"{happy[hour]} {'Yes' if happy[hour] > 50 else 'No'}")