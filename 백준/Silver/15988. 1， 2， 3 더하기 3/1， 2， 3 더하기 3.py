import sys
input = sys.stdin.readline

x = 1_000_000_009

t = int(input())

dp = [0] * 1_000_001
dp[:3] = [1,1,2]

for i in range(3, 1_000_001):
    dp[i] = dp[i-1] % x + dp[i-2] % x + dp[i-3] % x

    
for _ in range(t):
    n = int(input())    
    print(dp[n]%x)