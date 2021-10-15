#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    return answer;
}

void tc1(){
	std::vector<std::vector<int>> routes = {{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}};

    int answer = solution(routes);
    if(answer == 2){
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