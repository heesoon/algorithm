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
queue = []
result = []

def is_in_map(y, x):
    if (y >= 0 and y < N) and (x >= 0 and x < N):
        return True
    
    return False

def bfs(y, x, c):
    global queue
    queue.append((y, x))
    map[y][x] = c

    while len(queue) != 0:
        t = queue[0]
        del queue[0]
        global depth
        depth += 1

        for i in range(0, 4):
            ny = t[0] + dy[i]
            nx = t[1] + dx[i]

            if (is_in_map(ny, nx) == True) and (map[ny][nx] == 1):
                map[ny][nx] = c
                queue.append((ny, nx))

def main():
    cnt = 1
    for y in range(0, N):
        for x in range(0, N):
            if map[y][x] == 1:
                global depth
                depth = 0
                cnt += 1
                bfs(y, x, cnt)
                result.append(depth)

    result.sort(reverse=True)
    print(cnt-1)
    for d in result:
        print(d, end=" ")
    print()
    
    print(*map, sep='\n')
    #pprint.pprint(map,  width=100, indent=1)

if __name__ == "__main__":
    main()