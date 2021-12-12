#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> bridge;

int solve(int y, int x, int c, std::string str){
	int ans = 0;

	if(c == str.size()){
		return 1;
	}

	for(int i = x; i < bridge[0].size(); i++){
		if(bridge[y][i] == str[c]){
			ans += solve((y+1) % 2, i+1, c+1, str);
		}
	}

	return ans;
}

void tc1(){
	int ans = 0;
	bridge.assign({"RINGSR", "GRGGNS"});

	ans = solve(0, 0, 0, "RGS") + solve(1, 0, 0, "RGS");
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
	ans = solve(0, 0, 0, "RINGS") + solve(1, 0, 0, "RINGS");
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
	ans = solve(0, 0, 0, "GG") + solve(1, 0, 0, "GG");
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