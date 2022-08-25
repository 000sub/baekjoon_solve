import sys
input = sys.stdin.readline
        
n, m = map(int, input().split())

def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
        
    return parent[i]

def union(a,b):
    a = find(a)
    b = find(b)

    if a>b:
        parent[a] = b
    else:
        parent[b] = a 
    
s = input()
if s=='0':
    truth = []
else:
    truth = list(map(int, s.split()))
    truth = truth[1:]

L = []
parent = [i for i in range(n+1)]
for t in truth:
    parent[t] = 0
    
for _ in range(m):
    tmp=list(map(int, input().split()))[1:]

    v = min(tmp)

    for i in tmp:
        union(i,v)
        
    L.append(tmp)

            

    
if not truth:
    print(m)

else:
    cnt = 0
    for l in L:
        flag = False
        for i in l:
            if find(i) == 0:
                flag = True
                break
        if not flag:
            cnt+=1
    print(cnt)
