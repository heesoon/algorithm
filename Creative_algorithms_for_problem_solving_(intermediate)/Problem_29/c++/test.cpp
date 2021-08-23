#include <iostream>
#include <string>

const int L = 3;
const int N = 6;
int cnt = 0;

std::string ans = "RGS";
char map[2][6] = {
	{'R', 'I', 'N', 'G', 'S', 'R'},
	{'G', 'R', 'G', 'G', 'N', 'S'}
};

void solve(int x, int y, int d, std::string str){
    //std::cout << x << ", " << y << ", " << str << std::endl;
    
	if(x == N){
        std::cout << x << ", " << y << ", " << str << std::endl;
       	if(ans == str){
        	cnt++;
			std::cout << x << ", " << y << ", " << "cnt : " << cnt << std::endl;
        }
		//std::cout <<" -------> " << x << ", " << y << ", " << str << std::endl;
		return;
	}

	for(int idx = x+1; idx < N+1; idx++){
		solve(idx, (d+1)%2, d+1, str+map[y][x]);
	}
}

int main(){
    std::string str;
	for(int y = 0; y < 2; y++){
		for(int x = 0; x < N; x++){
            str.clear();
			if(map[y][x] == 'R'){
				std::cout << " start ======== " << std::endl;
				solve(x, y, y, str);
			}
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}