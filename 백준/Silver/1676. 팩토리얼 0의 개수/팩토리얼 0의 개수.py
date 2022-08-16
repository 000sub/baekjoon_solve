import math

n = int(input())

st = str(math.factorial(n))
cnt=0
for l in st[::-1]:
    if l!='0':
        break
    cnt+=1

print(cnt)

