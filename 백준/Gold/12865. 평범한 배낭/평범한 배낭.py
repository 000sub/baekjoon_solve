n, k = map(int, input().split())
L=[(0,0)]
dp = [[0 for i in range(100001)] for j in range(101)]


for i in range(n):
    a,b = map(int, input().split())
    L.append((a,b))

dp[1][L[0][0]] = dp[1][L[0][1]]

for i in range(1,n+1):
    for j in range(1,k+1):
        if L[i][0] <= j:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-L[i][0]]+L[i][1])

        else:
            dp[i][j] = dp[i-1][j]
            
    
print(dp[n][k])
