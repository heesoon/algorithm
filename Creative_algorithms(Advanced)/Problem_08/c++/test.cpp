#include <iostream>
#include <vector>

int solution(int start, int end, const std::vector<int> &abilities) {
    int answer = 0;

    return answer;
}

void tc1(){
    int start = 1;
    int end = 15;
    std::vector<int> abilities{2, 5, 7};

    if(2 == solution(start, end, abilities)){
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