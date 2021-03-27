#include <iostream>
#include <vector>

int ans = 0;

void solve(int s, int n)
{
	if(s >= n)
	{
		if(s == n)
		{
			ans++;
		}
		return;
	}

	solve(s+1, n);
	solve(s+2, n);

	return;
}

void testCase1()
{
	solve(0, 3);
	std::cout << ans << std::endl;
	ans = 0;
}

int main()
{
	testCase1();
    return 0;
}