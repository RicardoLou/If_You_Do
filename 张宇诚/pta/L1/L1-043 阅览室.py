N = int(input())
for i in range(0, N) :
    count = 0
    average = 0
    Sbooks = {}
    while True :
        book, key, time = input().split()
        if book == '0' :
            break
        else :
            hh, mm = time.split(":")
            minutes = int(hh) * 60 + int(mm)
            if key == 'S' : 
                Sbooks[book] = minutes
            elif book in Sbooks.keys() :
                average += minutes - Sbooks[book]
                count += 1
                del Sbooks[book]
    if count == 0 : 
        print("0 0")
    else :
        average /= count
        print(f"{count} {average:.0f}")