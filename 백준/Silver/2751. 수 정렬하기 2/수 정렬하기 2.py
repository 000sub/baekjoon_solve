import random, sys

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

random.shuffle(arr)

def quicksort(arr):
    def sort(low, high):
        if low >= high:
            return

        mid = partition(low, high)
        sort(low, mid-1)
        sort(mid, high)

    def partition(low, high):
        pivot = arr[(low+high)//2]
        while low<=high:
            while arr[low] < pivot:
                low +=1
            while arr[high] > pivot:
                high -=1
            if low <= high:
                arr[low], arr[high] = arr[high], arr[low]
                low +=1
                high -=1
        return low

    return sort(0, len(arr) -1)


quicksort(arr)
for i in range(n):
    print(arr[i])
