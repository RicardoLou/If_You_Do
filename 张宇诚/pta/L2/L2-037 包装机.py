N, M, S = [int(v) for v in input().split()]

track = []

for i in range(0, N) : 
    track.append(list(input()))

nums = [int(v) for v in input().split()]
stack = []
pipeline = []

for i in range(0, len(nums) - 1) : 
    num = nums[i]
    if num == 0 : 
        if len(stack) != 0 : 
            pipeline.append(stack[0])
            del stack[0]
    elif len(stack) == S : 
        if len(track[num - 1]) != 0 : 
            pipeline.append(stack[0])
            stack[0] = track[num - 1][0]
            del track[num - 1][0]
    elif len(track[num - 1]) != 0 : 
        stack.insert(0, track[num - 1][0])
        del track[num - 1][0]

for ch in pipeline : 
    print(ch, end = "")