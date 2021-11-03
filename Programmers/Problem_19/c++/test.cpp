#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int cIdx = 0;
    int lIdx = 0, lCnt = 0;
    int rIdx = 0, rCnt = 0;
    std::string str(name.size(), 'A');

    //for(int cIdx = 0; cIdx < name.size(); cIdx++){
    while(1){

        if(str == name){
            break;
        }
    
        // count of going right
        rCnt = 0;
        while(str[rIdx] == name[rIdx]){
            rCnt++;
            rIdx++;
            rIdx = rIdx % name.size();
        }

        // count of going left
        lCnt = 0;
        while(str[lIdx] == name[lIdx]){
            lCnt++;
            lIdx--;
            //lIdx = name.size() + (lIdx % name.size()) - 1;
            if(lIdx < 0){
                lIdx = name.size() - 1;
            }
        }

        if(rCnt > lCnt){
            answer += lCnt;
            cIdx = lIdx;
        }
        else{
            answer += rCnt;
            cIdx = rIdx;
        }

        lIdx = rIdx = cIdx;
        answer += std::min(name[cIdx] - 'A', 'Z' - name[cIdx] + 1);
        str[cIdx] = name[cIdx];        
    }

    return answer;
}

void tc1(){
	std::string name = "JEROEN";

    int answer = solution(name);
    if(answer == 56){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string name = "JAN";

    int answer = solution(name);
    if(answer == 23){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
	std::string name = "AAABB";

    int answer = solution(name);
    if(answer == 4){
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