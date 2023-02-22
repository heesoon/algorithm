
originSet = set(range(1, 10001))
generatedSet = set()

for i in range(1, 10001):
    for j in str(i):
        i += int(j)
    generatedSet.add(i)

resultList = sorted(originSet - generatedSet)
for num in resultList:
    print(num)