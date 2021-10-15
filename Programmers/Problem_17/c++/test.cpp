#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    return answer;
}

void tc1(){
    int brown = 10;
	int yellow = 2;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({4, 3})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int brown = 8;
	int yellow = 2;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({3, 3})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    int brown = 24;
	int yellow = 24;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({8, 6})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
	tc2();
	tc3();
    return 0;
}