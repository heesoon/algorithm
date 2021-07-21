N = 4
maxWeight = 5

W = [2, 1, 3, 2]
V = [3, 2, 3, 2]

def solve(idx, rw):
    global N, W, V
    if idx == N:
        return 0
    
    if W[idx] > rw :
        return solve(idx+1, rw)
    else:
        return max(solve(idx+1, rw), solve(idx+1, rw - W[idx]) + V[idx])

def main():
    print(solve(0, maxWeight))

if __name__ == "__main__":
    main()