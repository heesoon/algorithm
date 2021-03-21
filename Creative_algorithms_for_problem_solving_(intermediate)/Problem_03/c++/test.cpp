#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

const int N = 7;
int depth = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[N][N] = {
	{0, 1, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 1, 1},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 0, 0}
};

std::vector<int> v;
std::queue<std::tuple<int, int>> q;

bool is_in_map(int y, int x)
{
	if( (y >= 0 && y < N) && (x >= 0 && x < N) )
	{
		return true;
	}
	
	return false;
}

void bfs(int y, int x, int c)
{
	std::tuple<int, int> pos = std::make_tuple(y, x);
	q.push(pos);
	map[y][x] = c;

	while(q.empty() != true)
	{
		std::tuple<int, int> pos = q.front();
		q.pop();

		int y = std::get<0>(pos);
		int x = std::get<1>(pos);

		depth++;

		for(int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if( (is_in_map(ny, nx) == true) && (map[ny][nx] == 1) )
			{
				std::tuple<int, int> npos = std::make_tuple(ny, nx);
				map[ny][nx] = c;
				q.push(npos);
			}
		}
	}
}

int main()
{
	int cnt = 1;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			if(map[y][x] == 1)
			{
				cnt++;
				depth = 0;
				bfs(y, x, cnt);
				v.push_back(depth);
			}
		}
	}

	std::cout << cnt - 1 << std::endl;
	std::sort(v.begin(), v.end(), [](int a, int b){
		return a > b;
	});

	std::vector<int>::iterator it = v.begin();
	for(; it != v.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
            std::cout << map[y][x] << " ";
		}
        std::cout << std::endl;
	}	
}