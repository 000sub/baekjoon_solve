import sys
from collections import deque

stack = deque()
op = []
L=[]
n = int(sys.stdin.readline())
for i in range(n):
    L.append(int(sys.stdin.readline()))

idx = 0
for i in range(1, n+1):
    stack.append(i)
    op.append('+')
    
    while len(stack) >0 and stack[len(stack)-1] == L[idx]:
        stack.pop()
        op.append('-')
        idx+=1


if len(stack)>0:
    print('NO')
else:
    for i in range(len(op)):
        print(op[i])