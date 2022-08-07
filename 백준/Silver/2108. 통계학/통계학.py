from collections import Counter
import sys
import decimal
import statistics as s

L=[]
N = int(sys.stdin.readline())
for i in range(N):
    L.append(int(sys.stdin.readline()))



modeL = s.multimode(L)
modeL.sort()

avg = round(decimal.Decimal(sum(L) / len(L)))

L.sort()
med = L[len(L)//2]

print(avg)
print(med)
if len(modeL) >1:
    print(modeL[1])
else:
    print(modeL[0])
print(max(L)-min(L))
