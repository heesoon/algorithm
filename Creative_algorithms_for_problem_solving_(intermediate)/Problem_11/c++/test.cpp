#include <iostream>
#include <vector>

const int a = 5;
const int b = 15;
int ans = 0x7FFFFFFF;
//std::vector<int> rc = {10, 5, 1, -1, - 5, -10};
std::vector<int> visited(41, 0);

void solve(int v, int c)
{
    std::cout << v << ", " << c << std::endl;
	if(v < a)
	{
        std::cout << "return1 ... " << std::endl;
		return;
	}
    
	if(v > b)
	{
        std::cout << "return2 ... " << std::endl;
		return;
	}

	if(c > b)
	{
        std::cout << "return3 ... " << std::endl;
		return;
	}
    
	if(v == b)
	{
		std::cout << "arrived ... " << std::endl;
		if(ans > c)
		{
			ans = c;
		}
		
		return;
	}

    solve(v+10, c+1); solve(v+5, c+1); solve(v+1, c+1);
    solve(v-10, c+1); solve(v-5, c+1); solve(v-1, c+1);
    /*
    if(v < b)
    {
	   solve(v+10, c+1); solve(v+5, c+1); solve(v+1, c+1);
    }
    else
    {
        solve(v-10, c+1); solve(v-5, c+1); solve(v-1, c+1);
    }
    */
}

int main()
{
	int c = 0;
	solve(a, c);
	
	std::cout << ans << std::endl;
	
    return 0;
}