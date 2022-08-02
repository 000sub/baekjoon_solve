n,m = map(int, input().split())
L = [0 for _ in range(m)]

def is_solution(l):
    return l==m

def backtrack(length):

    if is_solution(length):
        print((" ").join(map(str,L)))
        return
    
    if length==0:
        for i in range(1,n+1):
            L[0]=i
            backtrack(length+1)
        return

    for i in range(L[length-1]+1, n+1):
        L[length]=i
        backtrack(length+1)

backtrack(0)