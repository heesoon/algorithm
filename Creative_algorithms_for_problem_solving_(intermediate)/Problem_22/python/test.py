N = 7
W = [1, 3, 9, 27, 81, 243, 729]
T = [25, 40]
chk = []

def solve(idx, l, r, t):
    global N, W, chk
    if idx == N:
        if l == r:
            print(t, end=' ')
            for i in range(N):
                if chk[i] == 1:
                    print(W[i], end=' ')

            print(0, end=' ')
            for i in range(N):
                if chk[i] == 2:
                    print(W[i], end=' ')       

            print('\n')
        return
    
    chk[idx] = 1
    solve(idx+1, l+W[idx], r, t)

    chk[idx] = 2
    solve(idx+1, l, r+W[idx], t)

    chk[idx] = 0
    solve(idx+1, l, r, t)
        
def main():
    global chk, T
    chk.clear()
    chk = [0 for i in range(N)]
    for x in T:
        solve(0, x, 0, x)

if __name__ == "__main__":
    main()