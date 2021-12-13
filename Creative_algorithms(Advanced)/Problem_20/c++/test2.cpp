#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> bridge;

int solve(std::string str){
	int ans = 0;
	std::vector<std::vector<std::vector<int>>> DT(2, std::vector<std::vector<int>>(bridge[0].size(), std::vector<int>(str.size(), 0)));

	for(int i = 0; i < bridge[0].size(); i++){
		if(bridge[0][i] == str[0]) DT[0][i][0] = 1;
		if(bridge[1][i] == str[0]) DT[1][i][0] = 1;
	}

	for(int i = 0; i < bridge[0].size(); i++){
		for(int k = 1; k < str.size(); k++){
			if(bridge[0][i] == str[k]){
				for(int j = 0; j < i; j++){
					DT[0][i][k] += DT[1][j][k-1];
				}
			}

			if(bridge[1][i] == str[k]){
				for(int j = 0; j < i; j++){
					DT[1][i][k] += DT[0][j][k-1];
				}
			}
		}
	}

#if 0
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge[0].size(); j++){
			for(int k = 0; k < str.size(); k++){
				std::cout << DT[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
#endif

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < bridge[0].size(); j++){
			ans += DT[i][j][str.size()-1];
		}
	}

	//std::cout << ans << std::endl;
	return ans;
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