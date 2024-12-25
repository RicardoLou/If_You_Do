N = int(input())
lst = [int(v) for v in input().split()]
min_ab = min(lst)
print(f"{min_ab} {lst.count(min_ab)}")

max_ab = max(lst)
print(f"{max_ab} {lst.count(max_ab)}")
