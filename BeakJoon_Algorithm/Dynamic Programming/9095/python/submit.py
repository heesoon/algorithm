T = int(input())

def add123(n):

    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4

    dp = [0]*(n+1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    for i in range(4, n+1):
        dp[i] = sum(dp[i-3:i])

    return dp[n]

for _ in range(T):
    N = int(input())
    print(add123(N))