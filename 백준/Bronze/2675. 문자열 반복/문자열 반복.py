N = int(input())
L = []

for _ in range(N):
    num, st = input().split()
    L.append((num, st))

for i in range(N):
    st = L[i][1]
    for j in st:
        print(int(L[i][0])*j, end='')
    print()
