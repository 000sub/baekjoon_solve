import sys, heapq
input = sys.stdin.readline
visited = [False] * 100_001
s, e = map(int, input().split())

def bfs(x, cnt):
   h = []
   heapq.heappush(h, (cnt, x))
   visited[x] = True
   
   while h:
       curcnt, curpos = heapq.heappop(h)

       if curpos==e:
           print(curcnt)
           break

       if curpos*2<=100_000 and not visited[curpos*2]:
           heapq.heappush(h, (curcnt, curpos*2))
           visited[curpos*2] = True

       if curpos+1<=100_000 and not visited[curpos+1] and curpos<e:
           heapq.heappush(h, (curcnt+1, curpos+1))
           visited[curpos+1] = True

       if curpos-1>=0 and not visited[curpos-1]:
           heapq.heappush(h, (curcnt+1, curpos-1))
           visited[curpos-1] = True
           
bfs(s,0)