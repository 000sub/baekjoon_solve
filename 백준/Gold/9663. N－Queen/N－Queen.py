N = int(input())
cnt = 0
L=[0 for _ in range(N)]

def is_proper(l):
    for i in range(l):
        if L[i] == L[l] or l-i == abs(L[l] -L[i]):
            return False
    return True
def make_candidate(length):
    global cnt

    if length==N:
        cnt+=1
        return 0


    for i in range(N):
        L[length]=i
        if is_proper(length):
            make_candidate(length+1)
                

make_candidate(0)
print(cnt)