#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

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

std::queue<std::tuple<int, int, int>> q;
std::vector<std::vector<bool>> visit;

bool is_in_map(int y, int x)
{
	if( (y >= 0 && y < N) && (x >= 0 && x < N) )
	{
		return true;
	}
	
	return false;
}

int find_short_path(int y, int x, int d)
{
	visit[y][x] = true;
	q.push(std::make_tuple(y, x, d));

	while(q.empty() == false)
	{
		int y, x, d;
		std::tie(y, x, d) = q.front();
		q.pop();

		if(map[y][x] == 'G')
		{
			return d;
		}

		for(int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nd = d + 1;

			if( (is_in_map(ny, nx) == true) && (map[ny][nx] == '.' || map[ny][nx] == 'G') && (visit[ny][nx] == false) )
			{
				visit[ny][nx] = true;
				q.push(std::make_tuple(ny, nx, nd));
			}
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
				depth = find_short_path(y, x, 0);
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