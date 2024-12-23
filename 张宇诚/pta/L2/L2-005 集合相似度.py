N = int(input())
lsts = []
for i in range(0, N) :
    lst = input().split()
    del lst[0]
    lsts.append(list(set(lst)))

K = int(input())

for i in range(0, K) :
    a, b = input().split()
    A = lsts[int(a) - 1]
    B = lsts[int(b) - 1]
    #求交集
    Nc = len(A + B) - len(set(A + B))
    #求并集
    Nt = len(A + B) - Nc #全集 - 交集
    print(f"{Nc / Nt * 100:.2f}%")