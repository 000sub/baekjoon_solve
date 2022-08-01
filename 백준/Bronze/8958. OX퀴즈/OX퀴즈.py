test_num = int(input())
tests = []

for _ in range(test_num):
    result = input()
    tests.append(result)

for rst in tests:
    score = 1
    final_score = 0
    for i in range(len(rst)):
        if rst[i] == 'O':
            final_score += score
            score += 1
        else:
            score = 1

    print(final_score)
