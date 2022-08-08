T = int(input())

L = []
for i in range(T):
    L.append(int(input()))

dp = [0] * 41

dp[0] = (1,0)
dp[1] = (0,1)

for i in range(2, len(dp)):
    dp[i] = (dp[i-1][0]+dp[i-2][0], dp[i-1][1]+dp[i-2][1])


for i in L:
    print(dp[i][0],dp[i][1])
