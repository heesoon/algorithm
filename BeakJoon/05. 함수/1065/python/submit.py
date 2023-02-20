N = int(input())

hansuCnt = 0

for n in range(1, N+1):
    if n < 100:
        hansuCnt += 1
    else:
        eachPosNums = list(map(int, str(n)))
        if eachPosNums[0] - eachPosNums[1] == eachPosNums[1] - eachPosNums[2]:
            hansuCnt += 1

print(hansuCnt)