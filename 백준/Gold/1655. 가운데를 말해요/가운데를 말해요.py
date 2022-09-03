import heapq,sys
input = sys.stdin.readline

n = int(input())

minh, maxh = [], []

a1 = int(input())
print(a1)

a2 = int(input())
if a1 > a2:
    print(a2)
    heapq.heappush(minh, a1)
    heapq.heappush(maxh, -1*a2)
else:
    print(a1)
    heapq.heappush(minh, a2)
    heapq.heappush(maxh, -1*a1)
    
for i in range(2,n):
    tmp = int(input())
    if i%2:
        heapq.heappush(maxh, -tmp)
    else:
        heapq.heappush(minh, tmp)

    
    if -1*maxh[0] > minh[0]:
        v1 = heapq.heappop(maxh)
        v2 = heapq.heappop(minh)
        heapq.heappush(minh, -1*v1)
        heapq.heappush(maxh, -1*v2)

    a,b = len(minh), len(maxh)
    if a==b:
        print(min(minh[0], -maxh[0]))
    else:
        print(minh[0])


    
