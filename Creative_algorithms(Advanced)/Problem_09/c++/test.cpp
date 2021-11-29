#include <iostream>
#include <vector>

const int MAX = 200 + 1;
std::vector<std::vector<int>> map = {
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 1, 0},
    {1, 1, 0, 0}
};

int solution(int n, int k) {

}

void tc1(){
    int n = 5;
    int m = 4;

    if(4 == solution(n, m)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}