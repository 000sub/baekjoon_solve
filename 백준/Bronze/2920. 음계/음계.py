nums = list(map(int, input().split()))
asc, des = True, True

for i in range(8):
    if asc == False and des == False:
        print("mixed")
        break
    if nums[i] != i+1:
        asc = False

    if nums[i] != 8-i:
        des = False

if asc == True:
    print("ascending")
if des == True:
    print("descending")
    
    
