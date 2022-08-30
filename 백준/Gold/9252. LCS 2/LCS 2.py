a = input()
b = input()

n, m = len(a), len(b)

dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

for i in range(1,m+1):
    for j in range(1,n+1):
        if a[j-1] != b[i-1]:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        else:
            dp[i][j] = dp[i-1][j-1]+1

print(dp[m][n])
rst = ""


while m>0 and n>0:
    if dp[m][n] > dp[m-1][n] and dp[m][n] > dp[m][n-1]:
        rst += b[m-1]
        m-=1
        n-=1
    if dp[m][n] == dp[m-1][n]:
        m-=1
    if dp[m][n] == dp[m][n-1]:
        n-=1

print(rst[::-1])