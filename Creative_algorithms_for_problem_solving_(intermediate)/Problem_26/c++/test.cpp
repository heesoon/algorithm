#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>

int maxDist = 98765431;

std::pair<int, int> s = {1, 1};
std::pair<int, int> e = {6, 6};

std::vector<std::pair<int, int>> tc = {
	{3, 5},
	{5, 5},
	{2, 3}
};

int distance(const std::pair<int, int> &a, const std::pair<int, int> &b){
	return (abs(std::get<0>(a) - std::get<0>(b)) + abs(abs(std::get<1>(a) - std::get<1>(b))));
}

void solve(int idx, const std::pair<int, int> &a, const std::pair<int, int> &b, int d){
	if(idx < tc.size()){
		solve(idx+1, tc[idx], b, d+distance(a, tc[idx]));
		solve(idx+1, a, tc[idx], d+distance(b, tc[idx]));
	}
	else{
		if(d < maxDist){
			maxDist = d;
		}
	}
}

int main(){
	solve(0, s, e, 0);
	std::cout << maxDist << std::endl;
	return 0;
}