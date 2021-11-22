#include <iostream>
#include <vector>

using namespace std;

long long solution(int n, int m) {
    long long answer = 0;

    return answer;
}

void tc1(){
    int n = 8;
    int m = 100;

    long long answer = solution(n, m);
    if(answer == 71){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc1(){
    int n = 8;
    int m = 2;

    long long answer = solution(n, m);
    if(answer == 1){
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