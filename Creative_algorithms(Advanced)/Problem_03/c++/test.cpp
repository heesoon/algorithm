#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100'000 + 1;

long long solution(int n, int m) {
    long long answer = 0;

    return answer;
}

void tc1(){
    int a = 5;
    int b = 3;

    long long answer = solution(a, b);
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

    long long answer = solution(a, b);
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