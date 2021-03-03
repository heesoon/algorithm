#include <iostream>
#include <vector>

const int N = 5;
int depth = 999999;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char map[N][N] = {
	{'#', 'S', '#', '#', '#'},
	{'#', '.', '.', '.', '#'},
	{'#', '.', '#', '.', '#'},
	{'#', '.', '.', '.', '.'},
	{'#', '#', '#', 'G', '#'}
};

std::vector<std::vector<bool>> visit;

bool is_in_map(int y, int x)
{
	if( (y >= 0 && y < N) && (x >= 0 && x < N) )
	{
		return true;
	}
	
	return false;
}

void find_short_path(int y, int x, int d)
{
	if(map[y][x] == 'G')
	{
		depth = depth > d ? d : depth;
	}

	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if( (map[ny][nx] == '.' || map[ny][nx] == 'G') && (visit[ny][nx] == false) && (is_in_map(ny, nx) == true) )
		{
			visit[ny][nx] = true;
			find_short_path(ny, nx, d+1);
			visit[ny][nx] = false;
		}
	}
}

int main()
{
	visit.assign(N, std::vector<bool>(N, 0));

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			if(map[y][x] == 'S')
			{
				visit[y][x] = true;
				find_short_path(y, x, 0);
			}
		}
	}

	if(depth == 999999)
	{
		depth = -1;
	}

	std::cout << depth << std::endl;
    return 0;
}