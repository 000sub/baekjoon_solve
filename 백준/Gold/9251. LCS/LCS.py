a = input()
b = input()



N, M = len(a), len(b)

dp = [[0 for _ in range(M+1)] for _ in range(N+1)]


for i in range(N+1):
    for j in range(M+1):
        if i==0 or j==0:
            dp[i][j] ==0

        elif a[i-1]!=b[j-1]:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        else:
            dp[i][j] = dp[i-1][j-1] + 1

print(dp[N][M])
