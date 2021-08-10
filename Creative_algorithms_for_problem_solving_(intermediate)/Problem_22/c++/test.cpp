#include <iostream>

const int N = 7;
int target[2] = {25, 40};
int weights[N] = {1, 3, 9, 27, 81, 243, 729};
int chk[N];

void solve(int idx, int l, int r, int t) {
	if(idx == N){
		if(l == r){
			std::cout << t << " ";
			for(int i = 0; i < N; i++){
				if(chk[i] == 1){
					std::cout << weights[i] << " ";
				}
			}

			std::cout << "0" << " ";
			for(int i = 0; i < N; i++){
				if(chk[i] == 2){
					std::cout << weights[i] << " ";
				}
			}
			std::cout << std::endl;		
		}
		return;
	}

	chk[idx] = 1;
	solve(idx+1, l+weights[idx], r, t);

	chk[idx] = 2;
	solve(idx+1, l, r+weights[idx], t);

	chk[idx] = 0;
	solve(idx+1, l, r, t);
}

int main(){

	for(auto t : target){
		solve(0, t, 0, t);
	}
	return 0;
}