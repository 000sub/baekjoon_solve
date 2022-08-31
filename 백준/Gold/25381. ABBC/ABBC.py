from collections import deque

st = input()
idxA, idxB = deque(), deque()
cnt=0
erased = []

for i in range(len(st)):
    if st[i]=='A':
        idxA.append(i)
    elif st[i]=='B':
        idxB.append(i)
    else:
        if idxB:
            curb_idx = idxB.popleft()
            if curb_idx < i:
                erased.append(curb_idx)
                erased.append(i)
                cnt+=1
            else:
                idxB.appendleft(curb_idx)
    
while idxA and idxB:
    cura_idx, curb_idx = idxA.popleft(), idxB.popleft()

    if cura_idx < curb_idx:
        cnt+=1
    else:
        idxA.appendleft(cura_idx)

print(cnt)