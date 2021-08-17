#include <iostream>
#include <vector>

int ga, gb, gc;

std::vector<int> tc[3] = {
	{6, 4 ,4, 4, 6, 9},
	{2, 10, 1},
	{1, 1, 1, 4, 6, 1, 1, 1, 1}
};

void debug(){
	for(int i = 0; i < 3; i++){
		for(auto x : tc[i]){
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
}

void solve(int idx, int a, int b, int c, const std::vector<int> &v){
	if(idx == v.size()){
		if(ga == 0 && gb == 0 && gc == 0){
			ga = a;
			gb = b;
			gc = c;
            
            return;
		}
		
		if( ((ga - gc) > (a - c)) && (ga > a) ){
			ga = a;
			gb = b;
			gc = c;			
		}

		return;
	}

	solve(idx+1, a+v[idx], b, c, v);

	solve(idx+1, a, b+v[idx], c, v);
	solve(idx+1, a, b, c+v[idx], v);
}

int main(){
	for(int i = 0; i < 3; i++){
		ga = 0, gb = 0, gc = 0;
		solve(0, 0, 0, 0, tc[i]);
		std::cout << ga << " " << gb << " " << gc << std::endl;
	}
	return 0;
}