#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_prime(int n)
{
    if(n < 2)
    {
        return false;
    }

/*    
	for(int i = 2; i < n; i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}
*/
	for(int i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}

	return true;
}

bool is_right_slice_prime(int n)
{
	int a = n;
	
	do
	{
		bool r = is_prime(a);
		if(r == false)
		{
			return false;
		}
        //std::cout << a << std::endl;
        
        a /= 10;
	}
	while(a);
	
	return true;
}

std::vector<int> solve(int n)
{
	int vs = std::pow(10, n-1);
	int ve = std::pow(10, n);
	
	std::vector<int> vc;
	
	for(int i = vs; i < ve; i++)
	{
		if(is_right_slice_prime(i) == true)
		{
			vc.emplace_back(i);
		}
	}
	
	return vc;
}

int main()
{
	int n = 2;
	//std::cout << "enter number (between 1 and 10) : ";
	//std::cin >> n;
	//std::cout << std::endl;
	
	auto v = solve(n);
	
	std::sort(v.begin(), v.end(), [](int a, int b){
		return a < b;
	});
	
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
    std::cout << v.size() << std::endl;
    
    return 0;
}