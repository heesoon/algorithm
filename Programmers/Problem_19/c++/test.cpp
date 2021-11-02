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

        //answer += std::min(name[cIdx] - 'A', 'Z' - name[cIdx] + 1);
        str[cIdx] = name[cIdx];
    
        // count of going right
        rCnt = 0;
        std::cout << "-------------" << std::endl;
        while(str[rIdx] == name[rIdx]){
            rCnt++;
             std::cout << "rIdx : " << rIdx <<", " << "rCnt : " << rCnt << " => " <<   (rIdx + rCnt) % name.size() << std::endl;
            rIdx = (rIdx + rCnt) % name.size();
            if(rCnt == name.size() - 1){
                break;
            }
        }

        // count of going left
        lCnt = 0;
        std::cout << "-------------" << std::endl;
        while(str[lIdx] == name[lIdx]){
            lCnt++;
            std::cout << "lIdx : " << lIdx <<", " << "lCnt : " << lCnt << " => " <<  name.size() - (lIdx + lCnt) % name.size() << std::endl;
            lIdx = name.size() - 1 - (lIdx + lCnt) % name.size();
            if(lCnt == name.size() - 1){
                break;
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
    }

    std::cout << answer << std::endl;
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

int main(){
    //tc1();
	tc2();
    return 0;
}