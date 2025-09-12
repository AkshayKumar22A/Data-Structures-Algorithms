n =56789
num = n
Count = 0

while num >0:
    Count +=1
    LastDigit = num%10
    num = num//10
print("Total digits in ",n," is ",Count)