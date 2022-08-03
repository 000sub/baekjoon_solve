import math

m,n = map(int, input().split())

arr = [True] * (n+1)

n_sqrt = int(math.sqrt(n))
for i in range(2, n_sqrt+1):
    if arr[i] == True:
        for j in range(i*2, n+1, i):
            arr[j] = False

for i in range(m, n+1):
    if arr[i] and i > 1:
        print(i)