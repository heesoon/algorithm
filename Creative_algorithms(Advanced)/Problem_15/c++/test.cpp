#include <iostream>
#include <vector>

int solve1(const std::vector<int>& ar)
{
	int ans = 0xFFFFFFFF;

	for(int a = 0; a < ar.size(); a++)
	{
		for(int b = a; b < ar.size(); b++)
		{
			int s = 0;
			//std::cout << "[" << a << " ~ " << b << "] ";
			for(int c = a; c <= b; c++)
			{
				s += ar[c];
			}

			//std::cout << s << std::endl;

			if(s > ans)
			{
				ans = s;
			}
		}
	}

	return ans;
}

void testCase1()
{
	std::vector<int> ar = {6, -7, 3, -1, 5, 2};
	std::cout << solve1(ar) << std::endl;
}

int main()
{
	testCase1();
    return 0;
}