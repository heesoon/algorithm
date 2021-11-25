#include <iostream>
#include <vector>

using namespace std;

std::vector<int> solution(int l, const std::vector<std::vector<int>> &map) {
    std::vector<int> answer;

    return answer;
}

void tc1(){
    int l = 8;
    std::vector<std::vector<int>> map{
        {1, 1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1}
    };

    if(std::vector<int>{9, 7} == solution(l, map)){
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