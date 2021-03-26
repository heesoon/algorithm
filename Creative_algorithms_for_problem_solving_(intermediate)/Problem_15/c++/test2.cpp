#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

const int n = 8;
const int m = 9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//std::vector<std::vector<int>> S(102, std::vector<int>(102, 0));
std::vector<std::vector<int>> S(10, std::vector<int>(11, 0));
std::vector<std::vector<int>> data = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void debug(const std::vector<std::vector<int>>& a)
{
	std::vector<std::vector<int>>::const_iterator it;
	for(it = a.begin(); it != a.end(); it++)
	{
		std::vector<int>::const_iterator jt;
		for(jt = (*it).begin(); jt != (*it).end(); jt++)
		{
			std::cout << *jt << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void initialize()
{
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			//S[y+1][x+1] = data[y][x];
			S[y][x] = data[y][x];
		}
	}
}

bool is_inside(int y, int x)
{
	return ( (y >= 0 && y < n) && (x >= 0 && x < m) );
}

bool done()
{
	int cnt = 0;

	//debug(S);

	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			if(S[y][x] == -1 || S[y][x] > 2)
			{
				S[y][x] = 0;
			}
			else if(S[y][x] == 2 || S[y][x] == 1)
			{
				S[y][x] = 1;
				cnt++;
			}
		}
	}

	return (cnt == 0);
}

void solve(int y, int x)
{
	S[y][x] = -1;
	for(int i = 0; i < 4; i++)
	{
		if(is_inside(y+dy[i], x+dx[i]) == true)
		{
			if(S[y+dy[i]][x+dx[i]] == 0)
			{
				solve(y+dy[i], x+dx[i]);
			}
			else if(S[y+dy[i]][x+dx[i]] > 0)
			{
				S[y+dy[i]][x+dx[i]]++;
			}
		}
	}
}

int main()
{
	int r = 0;
	initialize();

	for(; done() == false; r++)
	{
		solve(0, 0);
	}

	std::cout << r << std::endl;

    return 0;
}