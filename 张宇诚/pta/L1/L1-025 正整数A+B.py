li = input().split(" ")
A, B = li[0], li[1]
a =A.isdigit() and int(A) >= 1 and int(A) <= 1000
b = B.isdigit() and int(B) >= 1 and int(B) <= 1000
if len(li) > 2 : 
    b = False
if a and b :
    print(f"{int(A)} + {int(B)} = {int(A) + int(B)}")
elif not a and not b:
    print("? + ? = ?")
elif not a :
    print(f"? + {int(B)} = ?")
else :
    print(f"{int(A)} + ? = ?")
