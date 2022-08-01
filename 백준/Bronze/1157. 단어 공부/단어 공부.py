word = input().upper()
letters= set(word)
max_cnt=0
max_letter = ''
dup = False

for letter in letters:
    cnt = word.count(letter)

    if max_cnt == cnt:
        dup = True
    if max_cnt < cnt:
        max_cnt = cnt
        max_letter = letter
        if dup == True:
            dup = False

if dup:
    print('?')
else:
    print(max_letter)