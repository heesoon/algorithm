#include <iostream>
#include <vector>
#include <algorithm>

unsigned int ans = 0;
unsigned int N = 4;
unsigned int r = 5;

std::vector<unsigned int> w{2, 1, 3, 2};
std::vector<unsigned int> v{3, 2, 3, 2};

unsigned int solve(int idx, int r)
{
	if(idx == N)
		return 0;
	else if(w[idx] > r)
		return solve(idx+1, r);
	else
		return std::max(solve(idx+1, r), solve(idx+1, r-w[idx])+v[idx]);
}

int main()
{
	std::cout << solve(0, r) << std::endl;
    return 0;
}