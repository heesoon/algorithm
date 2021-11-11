#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    std::queue<std::vector<int>> vq;
    vq.push({0, numbers[0]});
    vq.push({0, -numbers[0]});

    while(!vq.empty()){
        auto v = vq.front();
        vq.pop();
        int idx = v[0];
        int value = v[1];

        if(value == target && idx == numbers.size()-1){
            answer++;
        }

        if(idx < numbers.size() - 1){
            idx++;
            vq.push({idx, value+numbers[idx]});
            vq.push({idx, value-numbers[idx]});
        }
    }

    //std::cout << answer << std::endl;
    return answer;
}

void tc1(){
	std::vector<int> numbers = {1, 1, 1, 1, 1};
	int target = 3;

    int answer = solution(numbers, target);
    if(answer == 5){
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