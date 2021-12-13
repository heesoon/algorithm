#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> bridge;

int solve(std::string str){
	std::vector<std::vector<std::vector<int>>> DT(2, std::vector<std::vector<int>>(bridge.size(), std::vector<int>(str.size(), 0)));

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge.size(); j++){
			if(bridge[i][j] == str[0]){
				DT[i][j][0] = 1;
			}
		}
	}

	for(int k = 1; k < str.size(); k++){
		int tmp1 = 0, tmp2 = 0;
		for(int j = 1; j < bridge.size(); j++){
			tmp1 += DT[1][j-1][k-1];
			if(bridge[0][j] == str[k]){
				DT[0][j][k] = tmp1;
			}

			tmp2 += DT[0][j-1][k-1];
			if(bridge[1][j] == str[k]){
				DT[1][j][k] = tmp2;
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge.size(); j++){
			for(int k = 0; k < str.size(); k++){
				std::cout << DT[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << DT[0][bridge.size()-1][str.size()-1] + DT[1][bridge.size()-1][str.size()-1] << std::endl;
	return DT[0][bridge.size()-1][str.size()-1] + DT[1][bridge.size()-1][str.size()-1];
}

void tc1(){
	int ans = 0;
	bridge.assign({"RINGSR", "GRGGNS"});

	ans = solve("RGS");

	if(3 == ans){
		std::cout << "Success" << std::endl;
	}
	else{
		std::cout << "Fail" << std::endl;
	}
}

void tc2(){
	int ans = 0;
	bridge.clear();
	bridge.assign({"SGNIRSGNIR", "GNIRSGNIRS"});
	ans = solve("RINGS");
	if(0 == ans){
		std::cout << "Success" << std::endl;
	}
	else{
		std::cout << "Fail" << std::endl;
	}
}

void tc3(){
	int ans = 0;
	bridge.clear();
	bridge.assign({"GGGGRRRR", "IIIIGGGG"});
	ans = solve("GG");
	if(16 == ans){
		std::cout << "Success" << std::endl;
	}
	else{
		std::cout << "Fail" << std::endl;
	}
}

int main(){
	tc1();
	tc2();
	tc3();
	return 0;
}

// https://stillchobo.tistory.com/100