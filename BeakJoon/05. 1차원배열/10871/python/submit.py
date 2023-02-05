N, X = map(int, input().split())
nlist = list(map(int, input().split()))
rlist = [x for x in nlist if x < X]
print(' '.join(map(str, rlist)))