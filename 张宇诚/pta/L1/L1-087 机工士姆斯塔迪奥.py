N, M, Q = [int(v) for v in input().split()]
row_reduce = 0
col_reduce = 0
safe = N * M
rows = []
cols = []
for i in range(0, Q) :
    T, C = input().split()
    c = int(C)
    if T == '0' :
        if not c in rows :
            safe -= M - col_reduce
            row_reduce += 1
            rows.append(c)
    else :
        if not c in cols :
            safe -= N - row_reduce
            col_reduce += 1
            cols.append(c)
print(safe)