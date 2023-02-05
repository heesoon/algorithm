
oList = []

for i in range(1, 31):
    oList.append(i)

for i in range(0, 28):
    n = int(input())
    #del(oList[n-1])
    oList.remove(n)

for x in oList:
    print(x)