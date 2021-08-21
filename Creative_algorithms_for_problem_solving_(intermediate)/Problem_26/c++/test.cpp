#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>

int prevAIndex, prevBIndex;
int maxDist = 98765431;

std::vector<std::pair<int, int>> tc = {
	{1, 1},
	{3, 5},
	{5, 5},
	{2, 3},
	{6, 6}
};

int distance(int a, int b){
	int xd = abs(std::get<0>(tc[a]) -std::get<0>(tc[b]));
	int yd = abs(std::get<1>(tc[a]) -std::get<1>(tc[b]));

	return xd + yd;
}

void solve(int idx, int a, int b){
	if(idx < tc.size()){
		prevAIndex = a;
		prevBIndex = b;
		solve(idx+1, idx+1, b);
		solve(idx+1, a, idx+1);
	}
	else{
		
	}
}

int main(){
	return 0;
}