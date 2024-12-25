#难题

N = int(input())
M = [int(v) for v in input().split()]

for i in range(0, N) :
    print(f"#{i + 1}")
    v = i + 1
    for row in range(1, M[i] + 1) :
        stride = N - len([item for item in M if item < row])
        first_stride = N - len([idx for idx in range(0, N) if idx < i and M[idx] < row])
        first_stride -= len([idx for idx in range(0, N) if idx > i and M[idx] < row - 1])
        if first_stride == 1 : first_stride = 2
        if stride == 1 : stride = 2
        if row != 1 : v += first_stride
        for ii in range(0, 10) :
            print(v, end="")
            if ii != 9 : 
                print(" ", end="")
                v += stride
        print()