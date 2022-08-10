from collections import deque
import sys

L=[]
k = int(sys.stdin.readline())
stack = deque()

for i in range(k):
    a = int(sys.stdin.readline())
    if a==0:
        stack.pop()
    else:
        stack.append(a)

    
print(sum(stack))