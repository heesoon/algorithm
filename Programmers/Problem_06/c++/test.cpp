#include <iostream>
#include <vector>
#include <tuple>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;
    bool is_higher_priority = false;

    std::deque<std::tuple<int, int>> printer;
    for(auto const &p : priorities){
        printer.push_back({cnt++, p});
    }

    cnt = 1;
    while(!printer.empty()){
        is_higher_priority = false;
        auto front = printer.front();
        printer.pop_front();

        for(const auto& pair : printer){
            if(std::get<1>(front) < std::get<1>(pair)){
                is_higher_priority = true;
            }
        }

        if(is_higher_priority == true){
            printer.push_back(front);
        }
        else{
            if(std::get<0>(front) == location){
                break;
            }
            else{
                cnt++;
            }
        }
    }
    
    answer = cnt;
    return answer;
}

void tc1(){
    std::vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    int answer = solution(priorities, location);
    if(answer == 1){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    int answer = solution(priorities, location);
    if(answer == 5){
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