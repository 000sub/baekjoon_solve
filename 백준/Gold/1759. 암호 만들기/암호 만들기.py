l, c = map(int, input().split())
chars = list(input().split())
chars.sort()

vowel = set(['a','e','i','o','u'])
res = []

def dfs(x, st):

    if len(st)==l:
        cnt = len(set(st) & vowel)
        if cnt>=1 and len(st)-cnt >=2 :
            res.append(st)
        return


    for i in range(x+1,c):
        dfs(i, st+chars[i])
    
    

for k in range(c):
    dfs(k, chars[k])

for k in res:
    print(k)