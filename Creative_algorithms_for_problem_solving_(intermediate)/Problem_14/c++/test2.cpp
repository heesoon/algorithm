#include <iostream>
#include <algorithm>

const int n = 6;
const int m = 60;
const int a[n] = {0, 30, 10, 20, 35, 40};
const int c[n] = {0, 3, 0, 3, 5, 4};

// 결과값을 리턴하는 함수 버전, 기존은 void 형이였음.
int solve(int i, int r)
{
	if(i == 0)
	{
		if(r <= 0)
		{
			return 0;
		}
		else
		{
			return n*100;
		}
	}
	
	if(r <= 0)
	{
		return solve(i-1, r);
	}
	else
	{
		return std::min(solve(i-1, r), solve(i-1, r-a[i]) + c[i]);
	}
}

int main()
{
	std::cout << solve(n, m) << std::endl;
    return 0;
}