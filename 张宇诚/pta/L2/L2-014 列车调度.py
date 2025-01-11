N = int(input())
queue = [int(v) for v in input().split()]
tracks = []

#二分搜索
def getInsertPos(bus) :
    global tracks
    left, right = 0, len(tracks) - 1
    mid = (left + right) // 2
    while left <= right :
        if bus < tracks[mid] :
            if mid == 0 or bus > tracks[mid - 1] :
                return mid
            else :
                right = mid - 1
        else :
            left = mid + 1
        mid = (left + right) // 2
    return -1

for bus in queue :
    pos = getInsertPos(bus)
    if pos == -1 :
        tracks.append(bus)
    else :
        tracks[pos] = bus
print(len(tracks))