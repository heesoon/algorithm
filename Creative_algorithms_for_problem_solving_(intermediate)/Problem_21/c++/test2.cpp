#include <iostream>
#include <vector>
#include <tuple>

const int N = 11;
int ans = 0x7fffffff;

std::vector<std::tuple<int, int, int>> Paths ={
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

// Vertex
int V[N];
// Graphe
int G[N][N];

void initialize()
{
	std::vector<std::tuple<int, int, int>>::size_type i = 0;
	for(; i < Paths.size(); i++)
	{
		int a, b, d;
		std::tie(a, b, d) = Paths[i];
		G[a][b] = G[b][a] = d;
	}
}

void solve(int a, int d, int n)
{
	if(a == n)
	{
		//std::cout << "arrival .." << std::endl;
		if(ans > d)
		{
			ans = d;
		}

		return;
	}

	for(int i = 1; i <=n; i++)
	{
		if(!V[i] && G[a][i])
		{
			V[i] = 1;
			solve(i, d+G[a][i], n);
			V[i] = 0;
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

	initialize();

	solve(1, 0, n-1);

	std::cout << ans << std::endl;

    return 0;
}