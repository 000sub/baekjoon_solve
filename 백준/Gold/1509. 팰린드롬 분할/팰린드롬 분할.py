import sys

st = sys.stdin.readline().rstrip()

N = len(st)

pal = [[False for _ in range(N+1)] for _ in range(N+1)]
dp = [1 for _ in range(N+1)]

for i in range(1, N+1):
    pal[i][i] = True

    if i<N and st[i-1] == st[i]:
        pal[i][i+1] = True

    
for k in range(2, N+1):
    for i in range(1,N-k+1):
        j = i+k
        if st[i-1]==st[j-1] and pal[i+1][j-1]:
            pal[i][j] = True


dp[0]=0
for j in range(1,N+1):
    dp[j] = dp[j-1]+1
    for i in range(1,j+1):
        if pal[i][j]:
            dp[j] = min(dp[j], dp[i-1]+1)
    

print(dp[N])         