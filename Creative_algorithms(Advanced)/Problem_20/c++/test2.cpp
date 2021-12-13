#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> bridge;

int solve(std::string str){
	std::vector<std::vector<std::vector<int>>> DT(2, std::vector<std::vector<int>>(bridge.size(), std::vector<int>(str.size(), 0)));

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge.size(); j++){
			for(int k = 0; k < str.size(); k++){
				if(bridge[i][j] == str[k]){
					DT[i][j][k] = 1;
				}
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge.size(); j++){
			for(int k = 1; k < str.size(); k++){
				if(bridge[i][j] == str[k]){
					DT[i][j][k] += DT[1-i][j][k-1];
				}
			}
		}
	}

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