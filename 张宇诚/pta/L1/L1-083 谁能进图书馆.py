min_age, and_age, ask1_age, ask2_age = [int(v) for v in input().split()]

old_id = 0
old_age = max([ask1_age, ask2_age])
child_age = min([ask1_age, ask2_age])
if old_age == ask1_age :
    old_id = 1
else :
    old_id = 2

if child_age >= min_age :
    print(f"{ask1_age}-Y {ask2_age}-Y")
    print("huan ying ru guan")
elif old_age < min_age :
    print(f"{ask1_age}-N {ask2_age}-N")
    print("zhang da zai lai ba")
else :
    if old_age < and_age :
        if old_id == 1 :
            print(f"{ask1_age}-Y {ask2_age}-N")
        else :
            print(f"{ask1_age}-N {ask2_age}-Y")
        print(f"{old_id}: huan ying ru guan")
    else :
        print(f"{ask1_age}-Y {ask2_age}-Y")
        print(f"qing {old_id} zhao gu hao {3-old_id}")