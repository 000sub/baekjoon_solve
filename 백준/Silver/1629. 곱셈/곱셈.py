def mypow(a, b, x):
    if b==1:
        return a%x
    else:
        k = mypow(a,b//2,x)
        if b%2 == 0:
            return k*k%x
        else:
            return k*k*a%x

a, b, c = map(int, input().split())
print(mypow(a,b,c))
