import sys
input = sys.stdin.readline

n = int(input())
L = list(map(int, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]


for i in range(1,n+1):
    dp[i][i] = 1

for i in range(1,n+1):
    tmpL = L[:]
    for j in range(i+1,n+1):
        minval = min(tmpL[j-1], tmpL[j-2])
        tmpL[j-1]-=minval
        tmpL[j-2]-=minval

        if tmpL[j-2]==0 and tmpL[j-1]==0:
            dp[i][j] = 1
        else:
            dp[i][j] = 0

rst = [0] * (n+1)
rst[1] = 1

for i in range(2, n+1):
    rst[i] = rst[i-1]+1
    for j in range(0, i):
        if dp[j][i]==1:
            if rst[j-1]+i-j < rst[i]:
                 rst[i] = rst[j-1]+i-j
        
print(rst[-1])