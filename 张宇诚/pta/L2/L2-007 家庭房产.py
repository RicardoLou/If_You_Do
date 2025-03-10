N = int(input())
infos = {} #{编号 : [[父, 母], [孩子1, 孩子2, ...], 房产套数, 总面积], ...}
for i in range(0, N) : 
    info = [int(v) for v in input().split()]
    _id = info[0]
    father = info[1]
    mother = info[2]
    k = info[3]
    childs = []
    for j in range(4, 4 + k) : 
        childs.append(info[j])
    houseCount = info[-2]
    houseArea = info[-1]
    parents = []
    if father != -1 : parents.append(father)
    if mother != -1 : parents.append(mother)
    infos[_id] = [parents, childs, houseCount, houseArea]
    for parent in parents : 
        if not parent in infos.keys() : 
            infos[parent] = [[], [_id], 0, 0]
        elif not _id in infos[parent][1] : 
            infos[parent][1].append(_id)
    for child in childs : 
        if not child in infos.keys() : 
            infos[child] = [[_id], [], 0, 0]
        elif not _id in infos[child][0] : 
            infos[child][0].append(_id)

visited = []

#            result = [房产套数, 总面积, 家庭人数, 最小编号]
def dfs(_id, result) : 
    global infos, visited
    if _id in visited : 
        return
    visited.append(_id)
    info = infos[_id]
    result[0] += info[2]
    result[1] += info[3]
    result[2] += 1
    if _id < result[3] : 
        result[3] = _id
    for parent in info[0] : 
        dfs(parent, result)
    for child in info[1] : 
        dfs(child, result)

results = []

for _id in infos.keys() : 
    if _id in visited : 
        continue
    result = [0, 0, 0, 10000]
    dfs(_id, result)
    minimumId = result[3]
    number = result[2]
    houseArea = result[1]
    houseCount = result[0]
    results.append([minimumId, number, houseCount / number, houseArea / number])

results.sort(key = lambda x : (-x[3], x[0]))

print(len(results))
for result in results : 
    _id = str(result[0])
    if len(_id) < 4 : 
        _id = (4 - len(_id)) * '0' + _id 
    print(f"{_id} {result[1]} {result[2]:.3f} {result[3]:.3f}")