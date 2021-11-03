#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0;

    int idx = 0, sIdx = 0, eIdx = k + cnt;
    int vMax = 0, iMax = 0;
    while(cnt < number.size() - k){
        vMax = 0;
        for(idx = sIdx; idx <= eIdx; idx++){
            if(vMax < number[idx]){
                vMax = number[idx];
                iMax = idx;
            }
        }
        
        //std::cout << "sIdx : " << sIdx << ", " << "eIdx : " << eIdx << ", " << "iMax : " << iMax << std::endl;
        cnt++;
        sIdx = iMax + 1;
        eIdx =  k + cnt;
        answer += vMax;
    }

    //std::cout << answer << std::endl;
    return answer;
}

void tc1(){
	std::string number = "1924";
	int k = 2;
	
    std::string answer = solution(number, k);
    if(answer == "94"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	std::string number = "1231234";
	int k = 3;
	
    std::string answer = solution(number, k);
    if(answer == "3234"){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
	std::string number = "4177252841";
	int k = 4;
	
    std::string answer = solution(number, k);
    if(answer == "775841"){
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
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k); 
    for(int i = k-1;i >=0;i--){
        int j = 0;
        do{
            if(number[i] >= answer[j]){
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }else{
                break;
            }
        }while(1);
    }



    return answer;
}
*/