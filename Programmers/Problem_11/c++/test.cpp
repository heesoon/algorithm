#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer{0, 0};
    std::priority_queue<int, std::vector<int>, std::greater<int>> ipq;
    std::priority_queue<int, std::vector<int>> dpq;
    int cnt = 0;

    for(const auto &str : operations){
        int num;
        char cmd = str[0];
        std::stringstream numStr(str.substr(1));
        numStr >> num;

        switch(cmd){
            case 'I':
                ipq.push(num);
                dpq.push(num);
                cnt++;
                break;
            case 'D':
                if(cnt > 0){
                    if(num == -1){
                        dpq.pop();
                    }
                    else if(num == 1){
                        ipq.pop();
                    }
                    cnt--;
                }
                break;
        }
    }

    if(cnt == 0){
        answer[0] = 0;
        answer[1] = 0;
    }
    else{
        answer[0] = dpq.top();
        answer[1] = ipq.top();
    }

    return answer;
}

void tc1(){
    std::vector<std::string> operations = {"I 16","D 1"};

    std::vector<int> answer = solution(operations);
    if(answer == std::vector<int>({0, 0})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
     std::vector<std::string> operations = {"I 7","I 5","I -5","D -1"};

    std::vector<int> answer = solution(operations);
    if(answer == std::vector<int>({7, 5})){
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