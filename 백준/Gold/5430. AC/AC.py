import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    com = input().strip()
    n = int(input())
    L = eval(input())
    com = com.replace('RR','')

    if not n:
        print('error') if 'D' in com else print('[]')
        continue

    if com.count('D') > n:
        print('error')
        continue
    

    L2 =list(map(len, com.split('R')))
    start = sum(L2[::2])
    end = sum(L2[1::2])
    if end>0:
        L = L[start:-end]
    else:
        L = L[start:]

    if com.count('R')%2:
        L.reverse()

    print(str(L).replace(' ',''))