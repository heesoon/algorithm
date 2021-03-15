
def sumOfdivisor(n):
    sum = 0
    
    for i in range(1, n+1):
        if (n % i) == 0:
            sum = sum + i;
            
    return sum

def main():
    sum = 0
    n = int(input("input number : "))
    sum = sumOfdivisor(n)
    
    print(sum)

if __name__ == "__main__":
    main()