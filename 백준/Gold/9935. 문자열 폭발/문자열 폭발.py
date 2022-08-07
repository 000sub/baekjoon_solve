st = input()
bomb_st = input()
L = []

for s in st:
    L.append(s)
    if s==bomb_st[-1] and bomb_st == ''.join(L[-len(bomb_st):]):
        del L[-len(bomb_st):]


if L != []:
    print("".join(L))
else:
    print("FRULA")