#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;

    std::deque<std::tuple<int, int>> printer;
    for(auto const &p : priorities){
        printer.push_back({cnt++, p});
    }

    while(!printer.empty()){
        auto front = printer.front();
        printer.pop_front();
        auto max_pair = *std::max_element(printer.begin(), printer.end(), [](const std::tuple<int, int> &a, const std::tuple<int, int> &b){
            return std::abs(std::get<1>(a)) < std::abs(std::get<1>(b));});

        if(std::get<1>(front) < std::get<1>(max_pair)){
            printer.push_back(front);
        }
        else{
            if(std::get<0>(front) == location)
                break;
            answer++;
        }
    }

    return answer + 1;
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