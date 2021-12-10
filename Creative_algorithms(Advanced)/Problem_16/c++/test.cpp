#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100'000 + 1;

long long solution(int n, int m) {

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

void tc2(){
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