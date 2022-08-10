n = int(input())

dp = [0]*(n+1)

dp[1:4] = [0,1,1]

for i in range(4, n+1):
    if i%3 ==0:
        if i%2==0:
            dp[i] = min(dp[i//2]+1, dp[i//3]+1, dp[i-1]+1)
        else:
            dp[i] = min(dp[i//3]+1, dp[i-1]+1)
    elif i%2==0:
        dp[i] = min(dp[i//2]+1, dp[i-1]+1)

    else:
        dp[i] = dp[i-1]+1

print(dp[n])