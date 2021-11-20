#include <iostream>

using namespace std;

long long solution(int n, int r) {
    long long answer;

    return answer;
}

void tc1(){
    int n = 5;
    int r = 1;

    long long answer = solution(n, r);
    if(answer == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int n = 10;
    int r = 5;

    long long answer = solution(n, r);
    if(answer == 252){
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