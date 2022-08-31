n = int(input())
L = list(map(int, input().split()))

minval = 501

for i in range(n):
    for j in range(i+1,n):
        if (L[j]-L[i])%(j-i) != 0:
            continue
        
        d = (L[j]-L[i])//(j-i)
        a0 = L[i] - d*i
        val = 0

        for k in range(n):
            if L[k] != a0 +d*k:
                val+=1
        if val < minval:
            minval = val
        

print(minval)