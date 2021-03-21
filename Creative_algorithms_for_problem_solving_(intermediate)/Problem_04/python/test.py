ans = 0
N = 4

col = [0 for _ in range(0, 11)]
inc = [0 for _ in range(0, 21)]
dec = [0 for _ in range(0, 21)]

def solve(y):
    global ans

    if y > N:
        ans += 1
        return
    
    for x in range(1, N+1):
        if col[x] == 0 and inc[y+x] == 0 and dec[N-(y-x)+1] == 0:
            col[x] = inc[y+x] = dec[N-(y-x)+1] = 1
            solve(y+1)
            col[x] = inc[y+x] = dec[N-(y-x)+1] = 0

def main():
    N = input("Enter N : ")
    solve(1)
    print("ans : ", ans)

if __name__ == "__main__":
    main()