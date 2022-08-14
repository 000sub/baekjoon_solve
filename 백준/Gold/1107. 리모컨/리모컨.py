n = int(input())
m = int(input())

if m>0:
    unable = set(input().split())
else:
    unable = set()
    
minfind, maxfind = n, n
ans = abs(100-n)

while True:
    if m == 10:
        minans, maxans = float('inf'), float('inf')
        break
    if not (set(str(minfind)) & unable) or not (set(str(maxfind)) & unable):
        minans = min(ans, len(str(minfind))+(n-minfind))
        maxans = min(ans, len(str(maxfind))+(maxfind-n))
        break


    minfind-=1
    maxfind+=1

if minfind < 0 or set(str(minfind)) & unable:
    print(min(ans, maxans))
else:
    print(min(ans, minans))