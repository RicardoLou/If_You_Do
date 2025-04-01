'''
思路：
五种情况：
1.两个三角形：判断两个斜线是否等长
2.一个五边形 + 一个三角形：判断两个斜线是否等长
3.一个四边形 + 一个三角形：判断两个斜线是否等长
4.两个四边形：判断两个斜线是否等长 + 判断两个斜线对面的边是否等长
5.两个矩形：判断任意两个边是否等长
'''

#------defined---function------
#将一维数组变成二维数组 : [1, 2, 3, 4] = [[1, 2], [3, 4]]
def to2dList(lst1d) : 
    lst2d = []
    for i in range(0, len(lst1d), 2) : 
        lst2d.append([lst1d[i], lst1d[i + 1]])
    return lst2d

#将一个多边形或直移动到(0,0)坐标 : 左下角在(0, 0)
def translate(vertices) : 
    minX = min([vertex[0] for vertex in vertices])
    minY = min([vertex[1] for vertex in vertices])
    return [[vertex[0] - minX, vertex[1] - minY] for vertex in vertices]

#获取多边形的斜线
def getObliqueLines(vertices) : 
    edges = []
    for j in range(0, len(vertices)) : 
        nextVertex = vertices[j + 1] if j != len(vertices) - 1 else vertices[0]
        curVertex = vertices[j]
        if curVertex[0] != nextVertex[0] and curVertex[1] != nextVertex[1] : 
            edges.append(curVertex)
            edges.append(nextVertex)
    return translate(edges) if len(edges) != 0 else edges

#判断两个线是否等长
def same(edge_1, edge_2) : 
    x1 = edge_1[0][0] + edge_1[1][0]
    y1 = edge_1[0][1] + edge_1[1][1]
    x2 = edge_2[0][0] + edge_2[1][0]
    y2 = edge_2[0][1] + edge_2[1][1]
    if [x1, y1] == [x2, y2] or [x1, y1] == [y2, x2] : 
        return True
    return False

#获取四边形的斜线对面的边
def getOpposite(vertices) : 
    edges = []
    idx = 0
    for j in range(0, len(vertices)) : 
        nextVertex = vertices[j + 1] if j != len(vertices) - 1 else vertices[0]
        curVertex = vertices[j]
        edges.append([curVertex, nextVertex])
        if curVertex[0] != nextVertex[0] and curVertex[1] != nextVertex[1] : 
            idx = j
    if idx + 2 < 4 : 
        return translate(edges[idx + 2])
    else : 
        return translate(edges[idx - 2])
#------defined---end------

N = int(input())
for i in range(0, N) : 
    vertices_1 = translate(to2dList([int(v) for v in input().split()][1:]))
    vertices_2 = translate(to2dList([int(v) for v in input().split()][1:]))
    if len(vertices_1) < len(vertices_2) : 
        vertices_1, vertices_2 = vertices_2, vertices_1
    #边数大于5 或 一个五边形一个非三角形 不满足
    if len(vertices_1) > 5 or len(vertices_1) == 5 and len(vertices_2) != 3 : 
        print('NO')
        continue
    ObliqueLines_1 = getObliqueLines(vertices_1)
    ObliqueLines_2 = getObliqueLines(vertices_2)
    #5.两个矩形：判断任意两个边是否等长
    if len(ObliqueLines_1) == 0 and len(ObliqueLines_2) == 0 : 
        x1 = vertices_1[0][0] +  vertices_1[2][0]
        y1 = vertices_1[0][1] +  vertices_1[2][1]
        x2 = vertices_2[0][0] +  vertices_2[2][0]
        y2 = vertices_2[0][1] +  vertices_2[2][1]
        if x1 == x2 or x1 == y2 or y1 == y2 or y1 == x2 : 
            print("YES")
        else : 
            print('NO')
        continue
    #一个矩形一个非矩形不满足
    if len(ObliqueLines_1) == 0 or len(ObliqueLines_2) == 0 : 
        print('NO')
        continue
    #多边形有多于一个斜边 或两个斜边不等长 则不满足
    if len(ObliqueLines_1) > 2 or len(ObliqueLines_2) > 2 or not same(ObliqueLines_1, ObliqueLines_2) : 
        print('NO')
        continue
    #4.两个四边形：判断两个斜线是否等长 + 判断两个斜线对面的边是否等长
    if len(vertices_1) == 4 and len(vertices_2) == 4 : 
        opposite_1 = getOpposite(vertices_1)
        opposite_2 = getOpposite(vertices_2)
        if same(opposite_1, opposite_2) : 
            print('YES')
        else : 
            print('NO')
        continue
    print('YES')