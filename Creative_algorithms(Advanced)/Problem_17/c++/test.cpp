#include <iostream>
#include <vector>

int ans = 0x7FFFFFFF;

void solve(int m, int c, const std::vector<int>& ar)
{
	if(m > 730) return;

	if(m == 730)
	{
		if(ans > c)
		{
			ans = c;
		}

		return;
	}

	for(std::vector<int>::size_type n : ar)
	{
		solve(m+n, c+1, ar);
	}
}

void testCase1()
{
	std::vector<int> changes = {10, 50, 100, 500, 1250};
	solve(0, 0, changes);

	std::cout << ans << std::endl;
	ans = 0x7FFFFFFF;
}

int main()
{
	testCase1();
    return 0;
}