#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1'000'000'000;

int dist(const std::vector<int> &a, const std::vector<int> &b){
	return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}

int solve(const std::vector<std::vector<int>> &event){
	std::vector<std::vector<int>> DT(event.size(), std::vector<int>(event.size(), INF));

	for(int a = 0; a < event.size(); a++){
		for(int b = 1; b < event.size(); b++){
			if(a == b){
				continue;
			}
			else if(a > b){
				if(a-1 > b)	DT[a][b] = DT[a-1][b] + dist(event[a-1], event[a]);
				else{
					for(int k = 0; k < b; k++){
						DT[a][b] = std::min(DT[a][b], DT[k][b]+dist(event[k], event[b]));
					}
				}
			}
			else{
				if(b-1 > a)	DT[a][b] = DT[a][b-1] + dist(event[b-1], event[b]);
				else{
					for(int k = 0; k < b; k++){
						DT[a][b] = std::min(DT[a][b], DT[k][b]+dist(event[k], event[b]));
					}
				}
			}
		}
	}

	int ans = INF;
	for(int i = 0; i < event.size(); i++){
		ans = std::min(ans, std::min(DT[i][event.size()-1], DT[event.size()-1][i]));
	}

	return ans;
}

void tc1(){
	std::vector<std::vector<int>> event{{1, 1}, {6, 6}, {3, 5}, {5, 5}, {2, 3}};
	if(9 == solve(event)){
		std::cout << "Success" << std::endl;
	}
	else{
		std::cout << "Fail" << std::endl;
	}
}

int main(){
	tc1();
	return 0;
}