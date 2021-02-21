#include <iostream>
#include <vector>
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

bool is_in_map(int y, int x)
{
	if( (y >= 0 && y < N) && (x >= 0 && x < N) )
	{
		return true;
	}
	
	return false;
}

void dfs(int y, int x, int c)
{
	map[y][x] = c;
    depth += 1;
	
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if( (is_in_map(ny, nx) == true) && (map[ny][nx] == 1) )
		{		
			dfs(ny, nx, c);
		}
	}
}

int main()
{
	int count = 1;
	
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			if(map[y][x] == 1)
			{
				count++;
				depth = 0;
                dfs(y, x, count);
				v.push_back(depth);
			}
		}
	}
	
	std::cout << count -1 << std::endl;
	std::sort(v.begin(), v.end(), [](int a, int b){
		return a > b;
	});
	
	std::vector<int>::iterator itor = v.begin();
	for(; itor != v.end(); itor++)
	{
		std::cout << *itor << std::endl;
	}

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
            std::cout << map[y][x] << " ";
		}
        std::cout << std::endl;
	}
 
    return 0;
}