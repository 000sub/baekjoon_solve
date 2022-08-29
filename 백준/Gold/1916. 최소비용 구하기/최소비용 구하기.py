import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

n = int(input())
m = int(input())
edges = [[] for _ in range(n+1)]
distance = [INF]* (n+1)

def dijkstra(start):
    distance[start] = 0
    h = []
    heapq.heappush(h, (0, start))

    while h:
        dist, cur = heapq.heappop(h)

        if dist > distance[cur]:
            continue

        for d, n in edges[cur]:
            nextdist = dist + d

            if nextdist < distance[n]:
                distance[n] = nextdist
                heapq.heappush(h, (nextdist, n))

for _ in range(m):
    a,b,w = map(int, input().split())
    edges[a].append((w,b))

start, end = map(int, input().split())

dijkstra(start)
print(distance[end])
