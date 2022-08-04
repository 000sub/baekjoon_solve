N= int(input())
L = []
for i in range(N):
    s = input()
    if s not in L:
        L.append(s)

L.sort()
L.sort(key = lambda x: len(x))

for i in L:
    print(i)
