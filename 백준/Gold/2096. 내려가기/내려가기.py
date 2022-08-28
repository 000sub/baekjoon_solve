import sys
input = sys.stdin.readline

n = int(input())
dp = list(map(int, input().split()))
dp2 = dp[:]

for i in range(n-1):
    a,b,c = list(map(int, input().split()))
    x= max(dp[0], dp[1]) + a
    y= max(dp) + b
    z= max(dp[1], dp[2]) + c

    dp = [x,y,z]

    x = min(dp2[0], dp2[1]) + a
    y = min(dp2) + b
    z = min(dp2[1], dp2[2]) + c

    dp2 = [x,y,z]
    
print(max(dp), min(dp2))