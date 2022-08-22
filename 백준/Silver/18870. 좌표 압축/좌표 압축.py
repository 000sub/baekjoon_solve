N = int(input())
L = list(map(int, input().split()))
S = sorted(set(L))

for i in range(len(L)):
    target = L[i]
    start = 0
    end = len(S)-1

    while start<=end:
        mid = (start+end)//2

        if S[mid] > target:
            end = mid -1

        elif S[mid] < target:
            start = mid +1

        else:
            print(mid, end=' ')
            break
