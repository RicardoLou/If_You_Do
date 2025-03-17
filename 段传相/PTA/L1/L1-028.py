import math

def main():
    n=int(input())
    a=0
    while a<n :
        b=int(input())
        if b==2 or b==3 :
            print("Yes",end="\n")
            a+=1
            continue
        
        if b<=1 :
            print("No",end="\n")
            a+=1
            continue
        
        i=2
        while i<=int(math.sqrt(b)) :
            if b%i==0 :
                print("No",end="\n")
                break
            if i==int(math.sqrt(b)) :
                print("Yes",end="\n")
            i+=1
        
        a+=1
    return

main()
