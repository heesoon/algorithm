#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1'000'000'000;
std::vector<int> DT;

int solution(int k, const std::vector<int>& ar)
{
	if(k == 0)			return DT[0] = ar[0];
	else if(!DT[k])		return DT[k] = std::max(solution(k-1, ar) + ar[k], ar[k]);
	else 				return DT[k];
}

void tc1(){
	int answer = -INF;
	int k = 6;
	std::vector<int> ar{6, -7, 3, -1, 5, 2};

	DT.assign(k, 0);

	for(int i = 0; i < k; i++){
		answer = std::max(answer, solution(i, ar));
	}

	if(9 == answer){
		std::cout << "Sucess" << std::endl;
	}
	else{
		std::cout << "Fail" << std::endl;
	}
}

int main()
{
	tc1();
    return 0;
}

// refer to Kadane's algorithm