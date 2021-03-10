#include <iostream>

int cnt = 0;
int N = 0;
int chk[100][100][100];

void solve(int a, int b, int c)
{
	if( (a + b + c) == N )
	{
		if( (a <= b) && (b <= c) && (a + b > c) && chk[a][b][c] == 0)
		{
			chk[a][b][c] = 1;
			cnt++;
		}
		
		return;
	}

	solve(a+1, b, c);
	solve(a, b+1, c);
	solve(a, b, c+1);
}

int main()
{
	std::cout << "Enter Number : ";
	std::cin >> N;
	std::cout << std::endl;

	solve(0, 0, 0);

	std::cout << cnt << std::endl;

    return 0;
}