N, M = [int(v) for v in input().split()]
for i in range(0, N) :
    price = float(input())
    if price < M :
        print("On Sale!", end=f" {price:.1f}\n")