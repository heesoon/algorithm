#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    return answer;
}

void tc1(){
	int n = 6;
	std::vector<std::vector<int>> = edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    int answer = solution(n, edge);
    if(answer == 3){
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