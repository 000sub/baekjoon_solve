from collections import deque
import itertools

st = input()
stack = deque()
L = []
comb_L=[]
for i in range(len(st)):
    if st[i] == '(':
        stack.append(i)

    if st[i] == ')':
        L.append((stack.pop(), i))

for i in range(1, len(L)+1):
    for comb in itertools.combinations(L, i):
        comb_L.append(comb)

L = []

for subset in comb_L:
    new_st = list(st)
    for a,b in subset:
        new_st[a] = '$'
        new_st[b] = '$'

    new_st = "".join(new_st).replace('$', '')
    if new_st not in L:
        L.append(new_st)

L.sort()
for s in L:
    print(s)