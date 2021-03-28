#include <iostream>
#include <vector>

int ans = 0;

void solve(int m, std::vector<int>::size_type idx, const std::vector<int>& ar)
{
	if(idx == ar.size())
	{
		if( m <= 40 && m > ans)
		{
			ans = m;
		}

		return;
	}

	solve(m+ar[idx], idx+1, ar);
	solve(m, idx+1, ar);
}

void testCase1()
{
	std::vector<int> budgets = {7, 13, 17, 19, 29, 31};
	solve(0, 0, budgets);

	std::cout << ans << std::endl;
	ans = 0;
}

int main()
{
	testCase1();
    return 0;
}