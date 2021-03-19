#include <iostream>
#include <vector>
#include <tuple>

const int N = 11;
int value[N][N];
int bVisited[N][N];
int result = 0x7fffffff;

std::vector<std::tuple<int, int, int>> data ={
	{1, 2, 47},
	{1, 3, 69},
	{2, 4, 57},
	{2, 5, 124},
	{3, 4, 37},
	{3, 5, 59},
	{3, 6, 86},
	{4, 6, 27},
	{4, 7, 94},
	{5, 7, 21},
	{6, 7, 40},
};

std::vector<int> map[N];

void debug()
{
	for(int a = 0; a < N; a++)
	{
		for(int b = 0; b < N; b++)
		{
			std::cout.width(4);
			//std::cout.fill('*');
			std::cout << value[a][b];
		}
		std::cout << std::endl;
	}
	
    std::cout << std::endl;
	for(int a = 0; a < N; a++)
	{
        std::cout << a << " :";
		for(int b = 0; b < map[a].size(); b++)
		{
			std::cout.width(2);
			//std::cout.fill('*');
			std::cout << map[a][b];
		}
		std::cout << std::endl;
	}
}

void solve(int a, int d, int n)
{
	if(a == n)
	{
		if(result > d)
		{
			result = d;
		}
		
		return;
	}

	for(int i = 0; i < map[a].size(); i++)
	{
		int ni = map[a][i];

		if(bVisited[a][ni] == 0 && bVisited[ni][a] == 0)
		{
			bVisited[a][ni] = 1;
            bVisited[ni][a] = 1;
			solve(map[a][i], d + value[a][ni], n);
			bVisited[a][ni] = 0;
            bVisited[ni][a] = 0;
		}
	}
}

int main()
{
	int n = 8;
/*	
	std::cout << "Enter n : ";
	std::cin >> n;
	std::cout << std::endl;
*/	
	int m = 11;
/*
	std::cout << "Enter m : ";
	std::cin >> m;
	std::cout << std::endl;	
*/

	// update map by data
	//for(std::vector<std::tuple<int, int, int> >::size_type i = 0; i < data.size(); i++)
	for(int i = 0; i < m; i++)
	{
		int a, b, d;
		auto& t = data[i];
		std::tie(a, b, d) = t;

		value[a][b] = d;
		map[a].push_back(b);
		value[b][a] = d;
		map[b].push_back(a);		
	}
	
	//debug();
	
	solve(1, 0, n-1);
	
	std::cout << result << std::endl;
	
    return 0;
}