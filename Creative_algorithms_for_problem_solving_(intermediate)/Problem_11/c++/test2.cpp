#include <iostream>
#include <queue>
#include <tuple>

const int a = 7;
const int b = 34;

std::queue<std::tuple<int,int>> q;

int solve(int a)
{
	q.push(std::tuple<int, int>{a, 0});
	
	while(q.empty() == false)
	{
		int v = 0, c = 0;
		std::tie(v, c) = q.front(); q.pop();
		
		if(v == b)
		{
			return c;
		}
		else if(v < b)
		{
			q.push(std::tuple<int, int>{v+10, c+1});
			q.push(std::tuple<int, int>{v+5, c+1});
			q.push(std::tuple<int, int>{v+1, c+1});
		}
		else
		{
			q.push(std::tuple<int, int>{v-10, c+1});
			q.push(std::tuple<int, int>{v-5, c+1});
			q.push(std::tuple<int, int>{v-1, c+1});			
		}
	}
}

int main()
{
	std::cout << solve(a) << std::endl;
    return 0;
}