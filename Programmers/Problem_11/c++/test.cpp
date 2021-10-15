#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    return answer;
}

void tc1(){
    std::vector<std::string> operations = {"I 16","D 1"};

    std::vector<int> answer = solution(operations);
    if(answer == std::vector<int>({0, 0})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
     std::vector<std::string> operations = {"I 7","I 5","I -5","D -1"};

    std::vector<int> answer = solution(operations);
    if(answer == std::vector<int>({7, 5})){
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