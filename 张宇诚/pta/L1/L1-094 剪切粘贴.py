text = input()
N = int(input())
for i in range(0, N) :
    begin, end, begin_str, end_str = input().split()
    begin = int(begin)
    end = int(end)
    paste = text[begin - 1 : end]
    text = text[:begin - 1] + text[end:]
    pos = text.find(begin_str + end_str)
    if pos == -1 :
        text += paste
    else :
        front_text = text[:pos + len(begin_str)]
        end_text = text[pos + len(begin_str):]
        text = front_text + paste + end_text
print(text)
        