#include <iostream>
#include <vector>

int N = 2, M = 6;
int W = 1, H = 3;
int net[100][100] = {
	{1, 0, 2, 0, 4, 3},
	{3, 4, 0, 2, 0, 1},
};

int solve()
{
	int ans = 0;

	for(int y = 0; y < N-W+1; y++)
	{
		for(int x = 0; x < M-H+1; x++)
		{
			int r = 0;
			for(int yy = y; yy < y+W; yy++)
			{
				for(int xx = x; xx < x+H; xx++)
				{
					r += net[yy][xx];
				}
			}

			if(r > ans)
			{
				ans = r;
			}
		}
	}

	return ans;
}

int main()
{
	int r = solve();

	std::cout << r << std::endl;
    return 0;
}