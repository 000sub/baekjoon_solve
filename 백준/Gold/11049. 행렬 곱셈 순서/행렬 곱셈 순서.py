import sys

N = int(sys.stdin.readline())
row = [0] * (N+1)
col = [0] * (N+1)

for i in range(1,N+1):
    r, c = map(int, sys.stdin.readline().split())
    row[i] = r
    col[i] = c

dp = [[0 for i in range(N+1)] for j in range(N+1)]

for i in range(1, N):
    dp[i][i+1] = row[i] * col[i] * col[i+1]

for k in range(2,N):
    for i in range(1, N+1):
        for j in range(i+1, N+1):
            if j-i==k:
                dp[i][j] = min(dp[i][j-x]+dp[j+1-x][j]+row[i]*row[j+1-x]*col[j] \
                               for x in range(1,k+1))
                

print(dp[1][N])