#include <iostream>

int ans = 0x7FFFFFFF;
const int n = 5;
const int m = 60;
const int a[n] = {30, 10, 20, 35, 40};
const int c[n] = {3, 0, 3, 5, 4};

void solve(int i, int sa, int sc)
{
	if(i == n)
	{
		if(sa >= 60)
		{
			if(ans > sc)
			{
				ans = sc;
			}
		}
		
		return;
	}
	
	// 현재 앱의 메모리를 해제하는 경우
	solve(i+1, sa+a[i], sc+c[i]);
	// 현재 앱의 메모리를 해제하지 않는 경우
	solve(i+1, sa, sc);
	
	return;
}

int main()
{
	solve(0, 0, 0);
	std::cout << ans << std::endl;
    return 0;
}