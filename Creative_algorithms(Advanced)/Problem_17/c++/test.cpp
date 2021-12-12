#include <iostream>
#include <vector>
#include <algorithm>

const int M = 10'000+1;
const int INF = 1'000'000'000;

int solve(int m, const std::vector<int>& changes){
	std::vector<int> DT(M, INF);

	for(const auto &c : changes){
		DT[c] = 1;
	}

	for(int currMoney = changes[0]; currMoney <= m; currMoney++){
		for(auto i = 0; i < changes.size(); i++){
			if(currMoney - changes[i] >= 0) DT[currMoney] = std::min(DT[currMoney], DT[currMoney - changes[i]]+1);
		}
	}

	return DT[m];
}

void tc1(){
	int m = 730;
	std::vector<int> changes{10, 50, 100, 500, 1250};

	if(6 == solve(m, changes)){
		std::cout << "Success" << std::endl;
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