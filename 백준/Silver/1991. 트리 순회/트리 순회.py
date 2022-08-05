n = int(input())
L = {}

for i in range(n):
    root, left, right = input().split()
    L[root] =  (left, right)

def pre_traverse(node):
    print(node, end = '')
    if L[node][0] != '.':
        pre_traverse(L[node][0])
    if L[node][1] != '.':
        pre_traverse(L[node][1])

def in_traverse(node):
    if L[node][0] != '.':
        in_traverse(L[node][0])
    print(node, end = '')
    if L[node][1] != '.':
        in_traverse(L[node][1])

def post_traverse(node):
    if L[node][0] != '.':
        post_traverse(L[node][0])
    if L[node][1] != '.':
        post_traverse(L[node][1])
    print(node, end = '')


pre_traverse('A')
print()
in_traverse('A')
print()
post_traverse('A')
