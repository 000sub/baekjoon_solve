import sys
input = sys.stdin.readline

n = int(input())
L=[]
for _ in range(n):
    L.append(int(input()))
if n==1:
    print(L[-1])
elif n==2:
    print(L[0]+L[1])
elif n==3:
    print(sum(L) - min(L))
else:
    dp = [0 for _ in range(n)]

    dp[0] = L[0]
    dp[1] = L[0]+L[1]
    dp[2] = max(dp[1], L[0]+L[2], L[1]+L[2])

    for i in range(3, n):
        dp[i] = max(dp[i-1], dp[i-2]+L[i],\
                    dp[i-3]+L[i-1]+L[i])

    print(dp[-1])