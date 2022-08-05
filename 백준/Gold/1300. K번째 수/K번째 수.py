n = int(input())
k = int(input())

start = 0
end = n*n-1
while start<=end:
    mid = (start+end)//2
    cnt = 0
    for i in range(1, n+1):
        cnt+=min(n, mid//i)

    if cnt < k:
        start = mid +1
    else:
        end = mid -1

print(start)
