n = 3
ans = 0x7FFFFFFF
vx = [0 for i in range(n)]
d = [
	[1, 5, 3],
	[2, 4, 7],
	[5, 3, 5]
]

def solve(y, s):
    global n
    global ans
    global vx

    if y == n:
        if ans > s:
            ans = s
        return
    
    for x in range(0, n):
        if vx[x] == 0:
            vx[x] = 1
            solve(y+1, s+d[x][y])
            vx[x] = 0

def main():
    solve(0, 0)
    print(ans)

if __name__ == "__main__":
    main()