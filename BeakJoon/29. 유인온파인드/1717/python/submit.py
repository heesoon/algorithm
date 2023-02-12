import sys
input = sys.stdin.readline

parents = []

def init(n):
    global parents
    parents = [x for x in range(n+1)]

def find(x):
    if x == parents[x]:
        return x
    else:
        parents[x] = find(parents[x])
        return parents[x]

def union(a, b):
    ra = find(a)
    rb = find(b)

    if ra == rb:
        return
    
    if ra > rb:
        ra, rb = rb, ra
    
    parents[ra] = rb

n, m = map(int, input().split())
init(n)

while m > 0:
    p, a, b = map(int, input().split())
    if p == 0:
        union(a, b)
    else:
        if find(a) == find(b):
            print('YES')
        else:
            print('NO')
    m -= 1