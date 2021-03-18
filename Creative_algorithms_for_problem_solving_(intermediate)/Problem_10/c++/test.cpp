#include <iostream>
#include <vector>
#include <tuple>

const int N = 11;
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

int map[N][N];
int bVisited[N][N];

void debug()
{
	for(int a = 0; a < N; a++)
	{
		for(int b = 0; b < N; b++)
		{
			std::cout.width(4);
			//std::cout.fill('*');
			std::cout << map[a][b];
		}
		std::cout << std::endl;
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

		map[a][b] = d;
	}
	
	//debug();
	
    return 0;
}