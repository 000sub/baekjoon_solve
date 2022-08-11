from collections import deque


T= int(input())
for _ in range(T):
    N, M = map(int, input().split())
    queue = deque()
    L= list(map(int, input().split()))
    cnt=0

    for l in L:
        queue.append(l)
    

    while queue:
        maxnum = max(queue)
        a = queue.popleft()
        M-=1
        if not queue:
            cnt+=1
            break
        
        if a != maxnum:
            queue.append(a)
            if M==-1:
                M = len(queue)-1

        else:
            cnt+=1
            if M==-1:
                break
            
    print(cnt)
