#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    return answer;
}

void tc1(){
    std::vector<int> answers = {1,2,3,4,5};

    std::vector<int> answer = solution(answers);
    if(answer == std::vector<int>({1})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> answers = {1,3,2,4,2};

    std::vector<int> answer = solution(answers);
    if(answer == std::vector<int>({1,2,3})){
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