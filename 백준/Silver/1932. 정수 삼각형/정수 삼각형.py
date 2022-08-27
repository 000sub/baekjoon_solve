import sys
input = sys.stdin.readline

n = int(input())
L = []
dp = [[0]* i for i in range(1, n+1)]
for _ in range(n):
    L.append(list(map(int, input().split())))

if n==1:
    print(L[0][0])
else:
    dp[0][0] = L[0][0]
    dp[1][0] = dp[0][0] + L[1][0]
    dp[1][1] = dp[0][0] + L[1][1]
    for i in range(2,n):
        for j in range(i+1):
            if 0<j<i:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + L[i][j]
            elif i==j:
                dp[i][j] = dp[i-1][j-1]+L[i][j]
            else:
                dp[i][j] = dp[i-1][j]+L[i][j]

    print(max(dp[-1]))
