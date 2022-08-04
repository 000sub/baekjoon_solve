n = int(input())
L1 = list(map(int, input().split()))
m = int(input())
L2 = list(map(int, input().split()))

L1.sort()

for i in L2:
    start = 0
    end = n-1
    while start<=end:
        mid = (start+end)//2

        if L1[mid] < i:
            start = mid+1
        elif L1[mid] == i:
            break
        else:
            end = mid-1

    if L1[mid] != i:
        print(0)
    else:
        print(1)
