L, N = [int(v) for v in input().split()]
count = pow(26, L)
n = count - N    #正序第n个
for i in range(0, L) :
    ch = chr(97 + n % pow(26, L - i) // pow(26, L - i - 1))
    print(ch, end="")