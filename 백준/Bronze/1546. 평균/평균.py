N = int(input())
L = list(map(int,(input().split())))

score_sum = 0
for i in range(N):
    max_score = max(L)
    score_sum += L[i] / max_score *100

print(score_sum / N)