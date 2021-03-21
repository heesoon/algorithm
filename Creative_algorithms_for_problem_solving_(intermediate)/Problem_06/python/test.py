
N = 0
cnt = 0
chk = [[[0 for i in range(100)] for j in range(100)] for k in range(100)]

def solve(a, b, c):
    global chk
    global cnt
    if a + b + c == N:
        if (a <= b) and (b <= c) and (a + b > c) and (chk[a][b][c] == 0):
            chk[a][b][c] = 1
            cnt = cnt + 1
        return
    
    solve(a+1, b, c)
    solve(a, b+1, c)
    solve(a, b, c+1)

def main():
    global N
    N = int(input('Enter Number : '))
    solve(1, 1, 1)
    print(cnt)

if __name__ == "__main__":
    main()