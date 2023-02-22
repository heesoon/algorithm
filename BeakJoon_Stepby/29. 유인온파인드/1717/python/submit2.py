import sys
input = sys.stdin.readline

parents = []
rank = []

def init(n):
    global parents, rank
    parents = [x for x in range(n+1)]
    rank = [1] * (n+1)

def find(x):
    if x == parents[x]:
        return x
    else:
        parents[x] = find(parents[x])
        return parents[x]

def union(a, b):
    ra = find(a)
    rb = find(b)

    if rank[ra] > rank[rb]:
        ra, rb = rb, ra
    
    # 작은 tree ra를 큰 tree rb에 붙인다
    parents[ra] = rb
    
    if rank[ra] == rank[rb]:
        rank[rb] += 1

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