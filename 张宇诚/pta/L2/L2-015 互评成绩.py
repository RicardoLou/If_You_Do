N, k, M = [int(v) for v in input().split()]
Scores = []
for i in range(0, N) :
    scores = [int(v) for v in input().split()]
    scores.remove(max(scores))
    scores.remove(min(scores))
    Scores.append(sum(scores) / (k - 2))
Scores.sort()
for i in range(len(Scores) - M, len(Scores)) :
    print(f"{Scores[i]:.3f}", end = "")
    if i != len(Scores) - 1 :
        print(" ", end = "")
print()