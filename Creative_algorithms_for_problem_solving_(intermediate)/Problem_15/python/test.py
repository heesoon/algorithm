N = 11
ans = 0x7fffffff

Paths = [
    [1, 2, 47],
    [1, 3, 69],
    [2, 4, 57],
    [2, 5, 124],
    [3, 4, 37],
    [3, 5, 59],
    [3, 6, 86],
    [4, 6, 27],
    [4, 7, 94],
    [5, 7, 21],
    [6, 7, 40]
]

V = [0 for i in range(N)]
G = [[0 for i in range(N)] for j in range(N)]

def debug():
    for a in range(N):
        for b in range(N):
            print(G[a][b], end=" ")
        print()

def initialize():
    for data in Paths:
        (a, b, d) = data
        G[a][b] = d
        G[b][a] = d

def solve(a, d, n):
    global ans
    if a == n:
        if ans > d:
            ans = d
        return
    
    for b in range(1, n+1):
        if V[b] == 0 and G[a][b] != 0:
            V[b] = 1
            solve(b, d+G[a][b], n)
            V[b] = 0

def main():
    n = 8
    # n = input("input n : ")
    m = 11
    # m = input("input m : ")

    initialize()

    solve(1, 0, n-1)

    print(ans)

if __name__ == "__main__":
    main()