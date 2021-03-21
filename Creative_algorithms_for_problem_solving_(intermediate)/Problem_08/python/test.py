N = 2
M = 6
W = 1
H = 3

net = [
    [1, 0, 2, 0, 4, 3],
    [3, 4, 0, 2, 0, 1]
]

def solve():
    ans = 0

    for y in range(0, N-W+1):
        for x in range(0, M-H+1):
            r = 0
            for yy in range(y, y+W):
                for xx in range(x, x+H):
                    r += net[yy][xx]
            
            if r > ans:
                ans = r
    
    return ans

def main():
    r = solve()

    print(r)

if __name__ == "__main__":
    main()