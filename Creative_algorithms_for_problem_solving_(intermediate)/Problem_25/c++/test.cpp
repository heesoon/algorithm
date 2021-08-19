#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

std::vector<std::pair<int, int>> inputData = {
	{1, 8},
	{3, 9},
	{2, 2},
	{4, 1},
	{6, 4},
	{10, 10},
	{9, 7},
	{7, 6}
};

std::vector<int> newData;

int main(){
	std::sort(inputData.begin(), inputData.end(), [](auto &&a, auto &&b){
		return std::get<0>(a) <= std::get<0>(b);
	});

	/*
	for(auto &&v : inputData){
		std::cout << "{ " << std::get<0>(v) << ", " << std::get<1>(v) << " }" << std::endl;
	}
	*/

	for(auto &&v : inputData){
		newData.emplace_back(std::get<1>(v));
	}

	/*
	for(auto &&v : newData){
		std::cout << v << std::endl;
	}
	*/

	// get longest ordered array
	int longestCnt = 0;
	for(int i = 0; i < newData.size(); i++){
		int s = newData[i];
		int cnt = 0;
		for(int j = i; j < newData.size(); j++){
			if(s <= newData[j]){
				s = newData[j];
				cnt++;
			}
		}

		if(longest < cnt){
			longest = cnt;
		}
	}

	std::cout << inputData.size() - cnt << std::endl;

	return 0;
}