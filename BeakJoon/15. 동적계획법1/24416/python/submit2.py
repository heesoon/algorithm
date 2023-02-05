
def fibonacci(n):
    if n == 1 or n == 2:
        return 1

    return fibonacci(n-1) + fibonacci(n-2)

def fibonacci2(n):
    cnt = 0
    dp = [-1]*(n+1)
    dp[0], dp[1], dp[2] = 0, 1, 1
    
    for i in range(3, n+1):
        cnt += 1
        dp[i] = dp[i-1] + dp[i-2]

    return cnt

n = int(input())

print(fibonacci(n), fibonacci2(n))
