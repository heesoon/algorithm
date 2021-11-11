#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    std::vector<int> dpA(money.size(), 0);
    std::vector<int> dpB(money.size(), 0);

    dpA[0] = money[0];
    dpA[1] = std::max(money[0], money[1]);

    for(int i = 2; i < money.size() - 1; i++){
        dpA[i] = std::max(dpA[i-1], dpA[i-2] + money[i]);
    }

    dpB[0] = 0;
    dpB[1] = money[1];

    for(int i = 2; i < money.size(); i++){
        dpB[i] = std::max(dpB[i-1], dpB[i-2] + money[i]);
    }

    //answer = std::max(dpA[money.size() - 2], dpB[money.size() - 1]);

    //std::cout << answer << std::endl;
    return std::max(dpA[money.size() - 2], dpB[money.size() - 1]);
}

void tc1(){
	std::vector<int> money = {1, 2, 3, 1};

    int answer = solution(money);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::vector<int> money = {1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000};

    int answer = solution(money);
    if(answer == 3000){
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

/*
print(solution([1,1,4,1,4]), 8)
print(solution([1000,0,0,1000,0,0,1000,0,0,1000]), 3000)
print(solution([1000,1,0,1,2,1000,0]), 2001)
print(solution([1000,0,0,0,0,1000,0,0,0,0,0,1000]), 2000)
print(solution([1,2,3,4,5,6,7,8,9,10]), 30)
print(solution([0,0,0,0,100,0,0,100,0,0,1,1]), 201)
print(solution([11,0,2,5,100,100,85,1]), 198)
print(solution([1,2,3]), 3)
print(solution([91,90,5,7,5,7]), 104)
print(solution([90,0,0,95,1,1]), 185)
*/