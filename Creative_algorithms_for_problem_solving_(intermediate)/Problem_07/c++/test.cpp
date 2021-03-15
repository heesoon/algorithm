#include <iostream>
#include <vector>

unsigned int solve(const std::vector<unsigned int>& v, unsigned int n, unsigned int w)
{
	unsigned int result = 0;
	
	for(int i = 0; i < (n - w); i++)
	{
		unsigned int r = 0;
		
		for(int j = i; j < (i + w); j++)
		{
			r += v[j];
		}
		
		if(r > result)
		{
			result = r;
		}
	}
	
	return result;
}

int main()
{
	unsigned int N = 0;
	unsigned int W = 0;
	unsigned int result = 0;
	
	//std::vector<unsigned int> v(100, 0);
    std::vector<unsigned int> v{1, 0, 2, 0, 4, 3};
	
	std::cout << "Enter N : ";
	std::cin >> N;
	std::cout << std::endl;
	
	std::cout << "Enter W : ";
	std::cin >> W;
	std::cout << std::endl;
	
	result = solve(v, N, W);
	std::cout << result << std::endl;

    return 0;
}