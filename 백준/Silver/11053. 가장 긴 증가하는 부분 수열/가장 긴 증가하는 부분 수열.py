n = int(input())
L = [0]
L2 = list(map(int, input().split()))
L = L+L2
dp = [0] * (n+1)


dp[1] = 1

for i in range(2,n+1):
    maxcnt = 0
    for j in range(i):
        if L[i] > L[j] and maxcnt < dp[j]:
            maxcnt = dp[j]

    dp[i] = maxcnt+1

print(max(dp))