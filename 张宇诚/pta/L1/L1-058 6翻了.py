s = input()
substr = ""
newStr = ""
hasSix = False

def addStr() :
    global substr, newStr, hasSix
    six_count = substr.count("6")
    if six_count > 9 :
        substr = substr.replace("6", "") + "27"
    elif six_count > 3 :
        substr = substr.replace("6", "") + "9"
    newStr += substr
    substr = ""
    hasSix = False

for ch in s :
    if ch == '6' :
        hasSix = True
    elif hasSix == True :
        addStr()
    substr += ch

addStr()

print(newStr)