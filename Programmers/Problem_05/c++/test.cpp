#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while(progresses.size() > 0){
        //std::cout << progresses.size() << std::endl;
        for(std::vector<int>::size_type i = 0; i < progresses.size(); i++){
            progresses[i] = progresses[i] + speeds[i];
        }

        int cnt = 0;
        while(progresses.front() >= 100 && progresses.empty() == false){
            //std::cout << progresses.front() << std::endl;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            cnt++;
        }
        
        //std::cout << cnt << std::endl;

        if(cnt > 0 ){
            //std::cout << cnt << std::endl;
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