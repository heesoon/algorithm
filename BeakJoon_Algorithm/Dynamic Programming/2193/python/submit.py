
N = int(input())

DP = [0] * (N+1)
DP[1] = 1
for n in range(2, N+1):
    DP[n] = DP[n-2] + DP[n-1]

print(DP[N])