A, B = [], []
Arow, Acol = [int(v) for v in input().split()]
for r in range(0, Arow) :
    column = [int(v) for v in input().split()]
    A.append(column)
    
Brow, Bcol = [int(v) for v in input().split()]
for r in range(0, Brow) :
    column = [int(v) for v in input().split()]
    B.append(column)
    
if Acol != Brow :
    print(f"Error: {Acol} != {Brow}")
else :
    print(f"{Arow} {Bcol}")
    C = []
    for r in range(0, Arow) :
        column = []
        for c in range(0, Bcol) :
            s = 0
            for br in range(0, Brow) :
                s += A[r][br] * B[br][c]
            column.append(s)
        C.append(column)
    for col in C :
        for i in range(0, len(col)) :
            print(col[i], end="")
            if i != len(col) - 1 :
                print(" ", end="")
        print()