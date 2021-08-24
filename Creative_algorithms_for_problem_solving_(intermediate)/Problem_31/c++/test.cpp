#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> pipe = {0, 12, 50, 81};
std::vector<int> car = {0, 27, 73};
int visited[12];
int minValue = 987654321;

// a : 호수, b : 소방차 번호, 
void f(int a, int b, int v){
	if(b == car.size() - 1){
		minValue = std::min(minValue, v);
		return;
	}

	for(int idx = 1; idx <= pipe.size()-1; idx++){
		if(visited[idx] == 0){
			int dist = abs(pipe[idx] - car[b+1]);
            std::cout << idx << ", " << b+1 << ", " << dist << ", " << v << std::endl;
			visited[idx] = 1;
			f(idx, b+1, v+dist);
			visited[idx] = 0;
		}
	}
}

int main(){
	f(0, 0, 0);
	std::cout << minValue << std::endl;
	return 0;
}