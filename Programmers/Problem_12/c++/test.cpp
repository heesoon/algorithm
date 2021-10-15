#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    return answer;
}

void tc1(){
    std::vector<int> array = {1, 5, 2, 6, 3, 7, 4};
	std::vector<std::vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    std::vector<int> answer = solution(array, commands);
    if(answer == std::vector<int>({5, 6, 3})){
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