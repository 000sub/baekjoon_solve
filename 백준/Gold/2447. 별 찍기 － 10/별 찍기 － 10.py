def print_star(i,j,n):
    if i%3 == 1 and j%3==1:
        return ' '
    else:
        if n>3:
            return print_star(i//3,j//3, n//3)
        else:
            return '*'




n = int(input())

for i in range(n):
    if i>0:
        print(st)
    st = ''
    for j in range(n):
        st += print_star(i,j,n)

print(st)
