
mem = [-1]*40
mem[0], mem[1], mem[2] = 0, 1, 1

def fibonacci(n):
    if n == 1 or n == 2:
        return 1

    return fibonacci(n-1) + fibonacci(n-2)

def fibonacci2(n):
    #print("fibonacci2", n)
    if n <= 0:
        return 0, 0
    
    if mem[n] != -1:
        return mem[n] , 0

    a, b = fibonacci2(n-1)
    c, d = fibonacci2(n-2)
    mem[n], cnt = a + c, b + d + 1
    return mem[n], cnt

n = int(input())

print(fibonacci(n), fibonacci2(n)[1])
