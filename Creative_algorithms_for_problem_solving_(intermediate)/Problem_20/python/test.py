N = 6
ans = 0
max = 40

activities = [
    7, 13, 17, 19, 29, 31
]

def solve(idx, s):
    global N, ans, max
    if idx == N:
        if s <= max and s > ans:
            ans = s
        return
    
    solve(idx+1, s+activities[idx])
    solve(idx+1, s)

def main():

    solve(0, 0)
    print(ans)

if __name__ == "__main__":
    main()