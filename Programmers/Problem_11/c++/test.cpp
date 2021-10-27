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
                        ipq.pop();
                    }
                    else if(num == 1){
                        dpq.pop();
                    }
                    cnt--;
                }
                break;
        }

        if(cnt == 0)
        {
            while(!ipq.empty()) ipq.pop();
            while(!dpq.empty()) dpq.pop();
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

void tc3(){
     std::vector<std::string> operations = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};

    std::vector<int> answer = solution(operations);
    if(answer == std::vector<int>({6, 5})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}


int main(){
    tc1();
	tc2();
	tc3();    
    return 0;
}

/*
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
*/