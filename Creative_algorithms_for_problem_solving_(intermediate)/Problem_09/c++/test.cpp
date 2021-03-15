#include <iostream>
#include <vector>
#include <tuple>

int net[20][20];
std::vector<std::tuple<int, int, int>> data{{3, 2, 1}, {3, 3, 2}, {3, 6, 2}, {3, 7, 2}, {3, 8, 2}, {3, 9, 1},
	{4, 3, 1}, {4, 4, 2}, {4, 9, 1},
	{5, 4, 1}, {5, 5, 2},
	{6, 5, 1}, {6, 6, 2}, {6, 7, 2},
	{7, 3, 1}, {7, 4, 1}, {7, 6, 1},
	{8, 7, 2}, {8, 8, 1},
};

bool is_in_net(int y, int x)
{
	if( (x >= 0 && x < 20) && (y >= 0 && y < 20) )
		return true;
	
	return false;
}

bool check_right(int y, int x)
{
	int cnt = 0;
	int i = 0;
	if( (is_in_net(y, x-1) == true) && (net[y][x] == net[y][x-1]) )
	{
		return false;
	}

	while( (x+i) < 20 )
	{
		if(net[y][x] == net[y][x+i])
		{
			cnt++;
		}
		i++;
	}

	if(cnt == 5)
	{
		return true;
	}

	return false;
}

bool check_down_right(int y, int x)
{
	int cnt = 0;
	int i = 0;
	if( (is_in_net(y-1, x-1) == true) && (net[y][x] == net[y-1][x-1]) )
	{
		return false;
	}

	while( ((x+i) < 20) && ((y+i) < 20) )
	{
		if(net[y][x] == net[y+i][x+i])
		{
			cnt++;
		}
		i++;
	}

	if(cnt == 5)
	{
		return true;
	}

	return false;
}

bool check_down(int y, int x)
{
	int cnt = 0;
	int i = 0;
	if( (is_in_net(y-1, x) == true) && (net[y][x] == net[y-1][x]) )
	{
		return false;
	}

	while( (y+i) < 20 )
	{
		if(net[y][x] == net[y+i][x])
		{
			cnt++;
		}
		i++;
	}

	if(cnt == 5)
	{
		return true;
	}

	return false;
}

bool solve(int y, int x)
{
	if(check_right(y, x) == true)
		return true;

	if(check_down_right(y, x) == true)
		return true;

	if(check_down(y, x) == true)
		return true;

	return false;	
}

int main()
{
	for(auto v : data)
	{
		int x, y, d;
		std::tie(y, x, d) = v;
		net[y][x] = d; 
	}

/*
	for(int y = 0; y < 20; y++)
	{
		for(int x = 0; x < 20; x++)
		{
			std::cout << net[y][x] << " ";
		}
		std::cout << std::endl;
	}
*/
	for(int y = 0; y < 20; y++)
	{
		for(int x = 0; x < 20; x++)
		{
			if(net[y][x] != 0)
			{
				if(solve(y, x) == true)
				{
					std::cout << y << " " << x << std::endl;
				}
			}
		}
	}

    return 0;
}