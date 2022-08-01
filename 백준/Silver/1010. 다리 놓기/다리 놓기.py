test_num = int(input())

for _ in range(test_num):
    n, m = map(int, input().split())

    dp = [[0 for _ in range(m+1)] for _ in range(m+1)]

    for i in range(n+1):
        for j in range(i, m+1):
            if i==1:
                dp[i][j] = j
            if i>1:
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]


    print(dp[n][m])
