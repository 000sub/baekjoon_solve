n = int(input())

x=1_000_000_007
def m_mul(a, b):
    rst = [[0,0],[0,0]]

    rst[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) %x
    rst[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) %x
    rst[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) %x
    rst[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) %x

    return rst

def fibo(n):
    if n==1:
        return [[1,1],[1,0]]
    else:
        k = fibo(n//2)
        if n%2==0:
            return m_mul(k,k) 
        else:
            return m_mul(m_mul(k, k), fibo(1)) 
    

n = n-1 if not n&1 else n

rst = fibo(n+1)[0][1] % x
print(rst)