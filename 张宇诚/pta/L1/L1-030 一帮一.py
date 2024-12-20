N = int(input())
students = []
for i in range(0, N) :
    sex, name = input().split()
    students.append([sex, name])

for i in range(0, N // 2) :
    sex = students[i][0]
    name = students[i][1]
    for j in range(len(students) - 1, len(students) - 1 - N // 2, -1) :
        if sex != students[j][0] :
            print(f"{name} {students[j][1]}")
            del students[j]
            break