import pprint

N = 5
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
map = [
    ['#', 'S', '#', '#', '#'],
    ['#', '.', '.', '.', '#'],
    ['#', '.', '#', '.', '#'],
    ['#', '.', '.', '.', '.'],
    ['#', '#', '#', 'G', '#']
]
goal = [0, 0]
visit = [[0]*N for _ in range(0, N)]
queue = []

def is_in_map(y, x):
    if (x >= 0 and x < N) and (y >= 0 and y < N) :
        return True
    
    return False

def find_short_depth(y, x, d):
    queue.append([y, x, d])

    while len(queue) != 0:
        t = queue[0]
        del(queue[0])

        for i in range(0, 4):
            ny = t[0] + dy[i]
            nx = t[1] + dx[i]
            nd = t[2] + 1

            if (is_in_map(ny, nx) == True) and (visit[ny][nx] == 0) and (map[ny][nx] == '.'):
                visit[ny][nx] = nd
                queue.append([ny, nx, nd])

def main():
    for y in range(0, N):
        for x in range(0, N):
            if map[y][x] == 'G':
                goal = [y, x]
                map[y][x] = '.'

    for y in range(0, N):
        for x in range(0, N):
            if map[y][x] == 'S':
                find_short_depth(y, x, 0)

    if visit[goal[0]][goal[1]] == 0:
        print(-1)
    else:
        print(visit[goal[0]][goal[1]])

if __name__ == "__main__":
    main()