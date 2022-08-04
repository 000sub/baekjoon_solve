n,m = map(int, input().split())
L = list(map(int, input().split()))

start = 1
end = max(L)

while start<=end:
    mid = (start+end)//2

    sumL = 0
    for i in L:
        if i > mid:
            sumL+=i-mid

    if sumL< m:
        end = mid -1
    else:
        start = mid +1

print(end)