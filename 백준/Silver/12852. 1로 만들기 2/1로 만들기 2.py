n = int(input())

#cnt , L

if n<=3:
    dp = [[] for _ in range(4)]
else:
    dp = [[0,[]] for _ in range(n+1)]


dp[1], dp[2], dp[3] = \
               [0,[1]],\
               [1,[1,2]],\
               [1,[1,3]]

    
for i in range(4, n+1):
    dp[i][0] = dp[i-1][0]+1
    dp[i][1] = dp[i-1][1]+[i]

    if i%2==0 and dp[i//2][0] <= dp[i-1][0]:
        dp[i][0] = dp[i//2][0]+1
        dp[i][1] = dp[i//2][1]+[i]

    if i%3==0 and dp[i//3][0] <= dp[i//2][0]:
        dp[i][0] = dp[i//3][0]+1
        dp[i][1] = dp[i//3][1]+[i]
    


print(dp[n][0])
for i in range(len(dp[n][1])-1,-1,-1):
    print(dp[n][1][i], end=' ')