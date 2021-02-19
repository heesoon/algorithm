import pprint

N = 7
depth = 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
map = [
    [0, 1, 1, 0, 1, 0, 0],
    [0, 1, 1, 0, 1, 0, 1],
    [1, 1, 1, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 1, 1],
    [0, 1, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 0],
    [0, 1, 1, 1, 0, 0, 0]
]
result = []

def is_in_map(y, x):
    if (x >= 0 and x < N) and (y >= 0 and y < N) :
        return True
    
    return False

def dfs(y, x, c):
    global depth
    depth += 1
    map[y][x] = c

    for i in range(0, 4):
        ny = y + dy[i]
        nx = x + dx[i]

        if (is_in_map(ny, nx) == True) and (map[ny][nx] == 1) :
            dfs(ny, nx, c)
        
def main():
    count = 1

    for y in range(0, N):
        for x in range(0, N):
            if map[y][x] == 1:
                count += 1
                global depth
                depth = 0
                dfs(y, x, count)
                result.append(depth)

    result.sort(reverse=True)
    print(count-1)
    for d in result:
        print(d, end=" ")
    print()
    
    print(*map, sep='\n')
    #pprint.pprint(map,  width=100, indent=1)

if __name__ == "__main__":
    main()