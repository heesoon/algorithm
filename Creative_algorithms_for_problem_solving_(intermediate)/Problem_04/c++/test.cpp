#include <iostream>
#include <vector>

int N = 0;
int ans = 0;
std::vector<int> col(10);
std::vector<int> inc(20);
std::vector<int> dec(20);

void solve(int y)
{
	if(y > N)
	{
		ans++;
		return;
	}

	for(int x = 1; x <= N; x++)
	{
		if(!col[x] && !inc[y+x] && !dec[N+(y-x)+1])
		{
			col[x] = inc[y+x] = dec[N+(y-x)+1] = 1;
			solve(y+1);
			col[x] = inc[y+x] = dec[N+(y-x)+1] = 0;
		}
	}
}

int main()
{
	std::cout << "Enter N : ";
	std::cin >> N;
	std::cout << std::endl;

	solve(1);

	std::cout << ans << std::endl;
}