import math

v = []

def is_prime(n):
    if n < 2:
        return False
    
    for x in [i for i in range(2, n+1) if i*i <= n]:
        if n%x == 0:
            return False
    
    return True

def is_right_slice_prime(n):
    while True:
        r = is_prime(n)
        if r == False:
            return False
      
        n = n // 10
        if n <= 0:
            break
    return True

def solve(n):
    global v
    
    #vs = math.pow(10, n-1)
    #ve = math.pow(10, n)
    vs = 10 ** (n-1)
    ve = 10 ** n
    
    #print(type(ve))
    for i in range(vs, ve):
        if is_right_slice_prime(i) == True:
            v.append(i)

def main():
    n = 2
    
    solve(n)
    
    for x in v:
        print(x)
    
    print(len(v))

if __name__ == "__main__":
    main()