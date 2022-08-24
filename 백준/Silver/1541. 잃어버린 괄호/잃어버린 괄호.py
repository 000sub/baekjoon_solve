import re

expr = input()
nums = list(map(int,re.split('[-|+]', expr)))
op = re.split('[0-9]', expr)
op = list(filter(None, op))

rst = nums[0]
flag = False
for i in range(len(op)):
    if flag:
        op[i] = '-'
    if op[i] == '-':
        flag = True
        
for i in range(len(op)):
    if op[i] == '+':
        rst = rst + nums[i+1]

    else:
        rst = rst - nums[i+1]

print(rst)
