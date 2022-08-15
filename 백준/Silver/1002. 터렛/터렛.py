T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int,input().split())

    dist1 = (y2-y1)**2 + (x2-x1)**2 
    dist2 = (r1+r2)**2
    dist3 = (r1-r2)**2

    if dist1 > dist2 or dist1 <dist3:
        ans = 0

    elif dist1 == dist2 or dist1 == dist3:
        ans = 1

    else:
        ans = 2

    if dist1 == 0 and r1==r2:
        ans = -1

    print(ans)