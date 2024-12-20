s = input().upper()
G = s.count("G")
P = s.count("P")
L = s.count("L")
T = s.count("T")
GPLT_C = [G, P, L, T]
GPLT_S = ["G", "P", "L", "T"]
while GPLT_C[0] != 0 or GPLT_C[1] != 0 or GPLT_C[2] != 0 or GPLT_C[3] != 0 :
    for i in range(0, 4) :
        if GPLT_C[i] != 0 :
            print(GPLT_S[i], end="")
            GPLT_C[i] -= 1
print()