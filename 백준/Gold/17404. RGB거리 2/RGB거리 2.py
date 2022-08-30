import sys
input = sys.stdin.readline

MAX = 1000*1000+1
n = int(input())
L = []
dp = [[0,0,0] for _ in range(n)]
for _ in range(n):
    L.append(list(map(int, input().split())))
ans = MAX

for k in range(3):
    for i in range(3):
        if i==k:
            dp[0][i] = L[0][i]
        else:
            dp[0][i] = MAX
    
    for i in range(1, n):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + L[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + L[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + L[i][2]

    for i in range(3):
        if i!=k:
            ans = min(dp[n-1][i],ans)
print(ans)