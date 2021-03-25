#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

const int n = 8;
const int m = 9;

std::vector<std::vector<int>> a2(102, std::vector<int>(102, 0));
std::vector<std::vector<int>> a1(102, std::vector<int>(102, 0));

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

void initialize()
{
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
		{
			a1[y+1][x+1] = data[y][x];
		}
	}
}

void copy()
{
	std::copy(a2.begin(), a2.end(), a1.begin());
	//std::copy(a2.begin(), a2.end(), std::back_inserter(a1));
}

void fill1(int y, int x)
{
	if( y < 1 || y > n || x < 1 || x > m ) return;
	if(a1[y][x] == 0)
	{
		a1[y][x] = 2;
		fill1(y+1, x);
		fill1(y-1, x);
		fill1(y, x+1);
		fill1(y, x-1);
	}
}

int check(int y, int x)
{
	int t = 0;
	if(a1[y+1][x] == 2) t++;
	if(a1[y-1][x] == 2) t++;
	if(a1[y][x+1] == 2) t++;
	if(a1[y][x-1] == 2) t++;

	return t;
}

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
}

int main()
{
	int cnt = 0;
	int hour = 0;
	initialize();
	std::copy(a1.begin(), a1.end(), a2.begin());
	//debug(a2);

	while(1)
	{
		fill1(1, 1);
		cnt = 0;

		for(int y = 1; y <= n; y++)
		{
			for(int x = 1; x <= n; x++)
			{
				if(a1[y][x] == 1 && check(y, x) >= 2)
				{
					a2[y][x] = 0;
					cnt++;
				}
			}
		}

		if(cnt == 0)
		{
			std::cout << hour << std::endl;
			break;
		}

		hour++;
		copy();

	}

    return 0;
}