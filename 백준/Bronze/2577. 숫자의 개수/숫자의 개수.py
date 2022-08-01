mul = 1

for _ in range(3):
    temp = int(input())
    mul*=temp

for i in range(10):
    print(str(mul).count(str(i)))
