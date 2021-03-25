#include <iostream>
#include <vector>

const int n = 3;
int ans = 0x7FFFFFFF;
int vx[n];

std::vector<std::vector<int>> d = {
	{1, 5, 3},
	{2, 4, 7},
	{5, 3, 5}
};

void solve(int y, int s)
{
	if(y == n)
	{
		if(ans > s)
		{
			ans = s;
		}
		
		return;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!vx[i])
		{
			vx[i] = 1;
			solve(y+1, s+d[i][y]);
			vx[i] = 0;
		}
	}
}

int main()
{
	solve(0, 0);
	std::cout << ans << std::endl;
    return 0;
}