#include <iostream>
#include <vector>

int N = 7;
int target[2] = {25, 40};
int weights[7] = {1, 3, 9, 27, 81, 243, 729};
std::vector<int> left;
std::vector<int> right;

void solve(int idx, int a, int b, int t) {
	if(idx == N) {
		return;
	}

	if(a == b) {
		std::cout << t << " ";
		
		for(auto l : left) {
			std::cout << l << " ";
		}

		std::cout << 0 << " ";

		for(auto r : right) {
			std::cout << r << " ";
		}
	}

	right.emplace_back(weights[idx]);
	sove(idx+1, a, b+weights[idx], t);
	right.pop_back();
	left.emplace_back(weights[idx]);
	solve(idx+1, a+weights[idx], b, t);
	left.pop_back();
}

int main(){
	for(aut tc : target) {
		solve(0, tc, 0);
	}

	return 0;
}