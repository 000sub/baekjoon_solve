x = 1_000_000_007

def Mmul(a,b):
    rst = [[0,0],[0,0]]
    rst[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) %x
    rst[0][1] = (a[0][0]*b[0][1] + a[1][0]*b[1][1]) %x
    rst[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) %x
    rst[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) %x

    return rst


def fibo(x):
    if x==1:
        return [[1,1],[1,0]]

    else:
        tmp = fibo(x//2)
        if x%2 == 0:
            return Mmul(tmp,tmp)
        else:
            return Mmul(Mmul(tmp,tmp), fibo(1))

n = int(input())
print(fibo(n)[0][1])
