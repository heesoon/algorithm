#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    return answer;
}

void tc1(){
    std::vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    int answer = solution(priorities, location);
    if(answer == 1){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    int answer = solution(priorities, location);
    if(answer == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    tc2();
    return 0;
}