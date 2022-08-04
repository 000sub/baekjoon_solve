k,n = map(int, input().split())
L =[]

def get_numofline(a, k):
    return sum(list(map(lambda x: x//k, a)))

for _ in range(k):
    temp = int(input())
    L.append(temp)

if k==0 and n==0:
    print(0)
else:
    start = 1
    end = max(L)

    while start<=end:
        mid = (start+end)//2
        numofline = get_numofline(L, mid)
        if numofline >= n:
            start = mid +1
        else:
            end = mid - 1
    print(end)