L=[]

N = int(input())

for i in range(N):
    a,b = map(int, input().split())
    L.append((a,b))


L.sort()

for l in L:
    print(l[0],l[1])