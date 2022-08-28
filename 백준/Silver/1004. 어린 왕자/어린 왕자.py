import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    cnt = 0
    for _ in range(n):
        flag1 = flag2 = False
        cx, cy, r = map(int, input().split())
        if (x1-cx)**2 + (y1-cy)**2 <= r**2:
            flag1 = True

        if (x2-cx)**2 + (y2-cy)**2 <= r**2:
            flag2 = True

        if flag1 ^ flag2:
            cnt+=1

    print(cnt)
