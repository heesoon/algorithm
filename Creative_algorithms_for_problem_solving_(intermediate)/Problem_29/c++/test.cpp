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

void solve(int c, int col, std::string str){
	if(col == N){
		if(ans == str){
			cnt++;
		}
		return;
	}

	std::cout << "c : " << c << ", " << "col : " << col << ", " << str << std::endl;

	for(int idx = col+1; idx < N; idx++){
		solve(c+1, idx, str+map[c%2][col]);
		solve(c+1, idx, str+map[(c+1)%2][col]);
	}
}

int main(){
	std::string str;
	solve(0, 0, str);
	std::cout << cnt << std::endl;
	return 0;
}