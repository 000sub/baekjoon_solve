import sys
input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())
D = {}

for _ in range(n):
    url, pw = input().strip().split()

    D[url] = pw


for _ in range(m):
    url = input().strip()

    print(D[url])
    print('\n')