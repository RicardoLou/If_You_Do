N, K, S = [int(v) for v in input().split()]
max_count = 0
d = {}
for i in range(0, N) :
    match_score, pat_score = [int(v) for v in input().split()]
    if match_score >= 175 :
        if pat_score >= S :
            max_count += 1
        else :
            if not match_score in d.keys() :
                d[match_score] = K - 1
            else :
                d[match_score] -= 1
            if d[match_score] >= 0 :
                max_count += 1
print(max_count)