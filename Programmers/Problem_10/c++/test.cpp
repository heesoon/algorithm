#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    return answer;
}

void tc1(){
    std::vector<std::vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};

    int answer = solution(jobs);
    if(answer == 9){
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