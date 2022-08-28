import sys
input = sys.stdin.readline

L = []
n = int(input())
for _ in range(n):
    s, e = map(int, input().split())
    L.append((s,e))

L.sort(key=lambda x: (x[1],x[0]))

end, cnt = 0,0
for i in range(n):
    s, e = L[i]

    if end<=s:
        end = e
        cnt += 1

print(cnt)