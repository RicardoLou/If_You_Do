N, D = [int(v) for v in input().split()]
numbers = [float(v) for v in input().split()]
prices = [float(v) for v in input().split()]

numbers_prices = []

for i in range(0, N) :
    numbers_prices.append([numbers[i], prices[i]])
    
numbers_prices.sort(key = lambda x: x[1] / x[0], reverse = True)

s = 0

for item in numbers_prices :
    number = item[0]
    price = item[1]
    if D >= number :
        s += price
        D -= number
    else :
        single_price = price / number
        s += D * single_price
        break
        
print(format(s, ".2f"))