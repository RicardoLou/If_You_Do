import copy
def printArr(a) -> str :
    s = ""
    for i in range(0, len(a)) :
        if i == 0 :
            s += '{'
        s += a[i]
        if i != len(a) - 1 :
            s += ','
        else :
            s += '}'
    return s

numbers = list(input())
arr = copy.deepcopy(numbers);
arr.sort(reverse=True)
arr = list(set(arr))
indices = {}
for i in range(0, len(arr)) :
    indices[arr[i]] = str(i)
index = []
for i in numbers :
    index += indices[i]
print(f"int[] arr = new int[]{printArr(arr)};")
print(f"int[] index = new int[]{printArr(index)};")