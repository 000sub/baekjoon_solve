remains=set()

for i in range(10):
    num = int(input())
    remains.add(num%42)
print(len(remains))
