#include <iostream>
#include <vector>

int ans = 0;

void solve(std::vector<int>::size_type idx, int sum, int target, const std::vector<int>& ar)
{
	if(idx == ar.size())
	{
		if( sum <= target && sum > ans)
		{
			ans = sum;
		}

		return;
	}

	solve(idx+1, sum+ar[idx], target, ar);
	solve(idx+1, sum, target, ar);
}

void testCase1()
{
	std::vector<int> budgets = {7, 13, 17, 19, 29, 31};
	solve(0, 0, 40, budgets);

	std::cout << ans << std::endl;
	ans = 0;
}

int main()
{
	testCase1();
    return 0;
}