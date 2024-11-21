from math import pow
for _ in range(int(input())):
    a = float(input())
    print("Case" , _+1 , end="")
    print(":", round(pow(a/2, 3/2)/6,4))