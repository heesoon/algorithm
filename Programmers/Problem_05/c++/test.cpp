#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int cnt = 0;
    while(!progresses.empty()){
        for(std::vector<int>::size_type i = 0; i < progresses.size(); i++){
            progresses[i] += speeds[i];
        }

        cnt = 0;
        for(const auto& p : progresses){
            if(p >= 100){
                cnt++;
            }
            else{
                break;
            }
        }

        if(cnt > 0){
            progresses.erase(progresses.begin(), progresses.begin() + cnt);
            speeds.erase(speeds.begin(), speeds.begin() + cnt);
            answer.push_back(cnt);
        }
    }

    return answer;
}

void tc1(){
    std::vector<int> progresses = {93, 30, 55};
    std::vector<int> speeds = {1, 30, 5};

    std::vector<int> answer = solution(progresses, speeds);
    if(answer == std::vector<int>({2, 1})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<int> progresses = {95, 90, 99, 99, 80, 99};
    std::vector<int> speeds = {1, 1, 1, 1, 1, 1};

    std::vector<int> answer = solution(progresses, speeds);
    if(answer == std::vector<int>({1, 3, 2})){
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