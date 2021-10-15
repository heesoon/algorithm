#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    return answer;
}

void tc1(){
	int n = 5;
	std::vector<std::vector<int>> = results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

    int answer = solution(n, results);
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