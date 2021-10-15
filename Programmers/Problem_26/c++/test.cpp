#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    return answer;
}

void tc1(){
	int m = 4;
	int n = 3;
	std::vector<std::vector<int>> routes = {{2, 2}};

    int answer = solution(routes);
    if(answer == 4){
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