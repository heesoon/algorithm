#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    return answer;
}

void tc1(){
    int n = 5;
	std::vector<int> lost = {2, 4};
	std::vector<int> reserve = {1, 3, 5};

    int answer = solution(n, lost, reserve);
    if(answer == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int n = 5;
	std::vector<int> lost = {2, 4};
	std::vector<int> reserve = {3};

    int answer = solution(n, lost, reserve);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    int n = 3;
	std::vector<int> lost = {3};
	std::vector<int> reserve = {1};

    int answer = solution(n, lost, reserve);
    if(answer == 2){
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