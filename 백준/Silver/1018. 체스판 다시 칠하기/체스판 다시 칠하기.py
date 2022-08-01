n,m = map(int, input().split())

board = [["" for _ in range(m)] for _ in range(n)]
chessboard = [["" for _ in range(8)] for _ in range(8)]
min_cnt = 100

#whole board
for i in range(n):
    row = input()
    for j in range(m):
        board[i][j] = row[j]

        
for i in range(n-7):
    for j in range(m-7):

        cnt_black, cnt_white = 0,0 #(black start case, white start case)

        #8x8 board slicing
        for k in range(8):
            for l in range(8):
                chessboard[k][l] = board[i+k][j+l]


        for k in range(8):
            for l in range(8):
                if (k+l)%2 == 0:
                    if chessboard[k][l] == 'B':
                        cnt_white+=1
                    else:
                        cnt_black+=1
                else:
                    if chessboard[k][l] == 'B':
                        cnt_black+=1
                    else:
                        cnt_white+=1

        #update min_cnt
        if min_cnt > cnt_black:
            min_cnt = cnt_black
        if min_cnt > cnt_white:
            min_cnt = cnt_white
            
print(min_cnt)