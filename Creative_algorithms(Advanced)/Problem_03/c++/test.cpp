#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m) {
    int answer = 0;

    return answer;
}

void tc1(){
    int a = 5;
    int b = 3;

    int answer = solution(a, b);
    if(answer == 3){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int a = 3;
    int b = 4;

    int answer = solution(a, b);
    if(answer == 3){
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