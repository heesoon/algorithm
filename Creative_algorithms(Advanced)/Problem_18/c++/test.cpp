#include <iostream>
#include <vector>
#include <algorithm>

int solve(int h, int w){
	std::vector<std::vector<int>> DT(h+1, std::vector<int>(w+1, 0));

	for(int a = 1; a <= h; a++){
		DT[a][0] = 1;
	}

	for(int a = 1; a <= h; a++){
		for(int b = 1; b <= w; b++){
			if((double)h/w <= (double)a/b){
				DT[a][b] = DT[a-1][b] + DT[a][b-1];
			}
		}
	}

	return DT[h][w];
}

void tc1(){
	int h = 3;
	int w = 4;

	if(5 == solve(h, w)){
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