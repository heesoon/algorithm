
N = 20
net = [ [0 for i in range(0, N)] for j in range(0, N) ]

data = [
    [3, 2, 1], [3, 3, 2], [3, 6, 2], [3, 7, 2], [3, 8, 2], [3, 9, 1],
    [4, 3, 1], [4, 4, 2], [4, 9, 1],
	[5, 4, 1], [5, 5, 2],
	[6, 5, 1], [6, 6, 2], [6, 7, 2],
	[7, 3, 1], [7, 4, 1], [7, 6, 1],
	[8, 7, 2], [8, 8, 1],
]

def is_in_net(y, x):
    if (x >= 0 and x < N) and (y >= 0 and y < N):
        return True
    return False

def check_right(y, x):
    cnt = 0
    i = 0
    
    if (is_in_net(y, x-1) == True) and (net[y][x] == net[y][x-1]):
        return False
    
    while (x+i) < 20:
        if net[y][x] == net[y][x+i]:
            cnt = cnt + 1
        i = i + 1
    
    if cnt == 5:
        return True
    
    return False

def check_down_right(y, x):
    cnt = 0
    i = 0
    
    if (is_in_net(y-1, x-1) == True) and (net[y][x] == net[y-1][x-1]):
        return False
    
    while ((x+i) < 20) and ((y+i) < 20):
        if net[y][x] == net[y+i][x+i]:
            cnt = cnt + 1
        i = i + 1
    
    if cnt == 5:
        return True
    
    return False

def check_up_right(y, x):
    cnt = 0
    i = 0
    
    if (is_in_net(y+1, x-1) == True) and (net[y][x] == net[y+1][x-1]):
        return False
    
    while ((x+i) < 20) and ((y-i) < 20):
        if net[y][x] == net[y-i][x+i]:
            cnt = cnt + 1
        i = i + 1
    
    if cnt == 5:
        return True
    
    return False

def check_down(y, x):
    cnt = 0
    i = 0
    
    if (is_in_net(y-1, x) == True) and (net[y][x] == net[y-1][x]):
        return False
    
    while (y+i) < 20:
        if net[y][x] == net[y+i][x]:
            cnt = cnt + 1
        i = i + 1
    
    if cnt == 5:
        return True
    
    return False

def solve(y, x):
	if check_right(y, x) == True:
		return True;

	if check_down_right(y, x) == True:
		return True;

	if check_up_right(y, x) == True:
		return True;

	if check_down(y, x) == True:
		return True;

	return False;	    

def main():
    for v in data:
        y = v[0]
        x = v[1]
        d = v[2]
        
        net[y][x] = d
        
    for y in range(0, N):
        for x in range(0, N):
            if net[y][x] != 0:
                if solve(y, x) == True:
                    print(y, x)

if __name__ == "__main__":
    main()