#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> pipe = {0, 12, 50, 81};
std::vector<int> car = {27, 73};
int visited[12];
long minValue = 987654321;

void f(int a, int b, int v){
	if(a == pipe.size()+1){
		return;
	}

	if(a > 0 && b > 0 && minValue > v){
		minValue = v;
	}
    
    std::cout << a << ", " << b << ", " << v << std::endl;

	for(int i = 1; i <= pipe.size(); i++){
		visited[a+1] = 1;
		if(visited[i] == 0){
			visited[i] = 1;
			int dist = abs(pipe[a+1] - 27) + abs(pipe[i] - 73);
			f(a+1, i, v+dist);
			visited[i] = 0;
		}
		visited[a+1] = 0;
	}
}

int main(){
	f(0, 0, 0);
	std::cout << minValue << std::endl;
	return 0;
}