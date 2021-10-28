#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    std::vector<std::vector<int>> brown_cd;
    std::vector<std::vector<int>> yellow_cd;

    for(int i = 1; i < brown; i++){
        if(brown % i == 0){
            //std::cout << i << ", " << brown/i << std::endl;
            brown_cd.push_back({i, brown/i});
        }
    }

    for(int i = 1; i < yellow; i++){
        if(yellow % i == 0){
            yellow_cd.push_back({i, yellow/i});
        }
    }

    std::cout << brown_cd.size() << ", " <<  yellow_cd.size() << std::endl;
    for(size_t i = 2; i < brown_cd.size(); i++){
        for(size_t j = 0; j < yellow_cd.size(); j++){
            std::cout << brown_cd[i][0] << ", " << yellow_cd[j][0] + 2 << std::endl;
            if((brown_cd[i][0] >= yellow_cd[j][0] + 2) && (brown_cd[i][1] >= yellow_cd[j][1] + 2)){
                answer.push_back(brown_cd[i][0]);
                answer.push_back(brown_cd[i][1]);
            }
        }
    }

    return answer;
}

void tc1(){
    int brown = 10;
	int yellow = 2;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({4, 3})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int brown = 8;
	int yellow = 2;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({3, 3})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    int brown = 24;
	int yellow = 24;

    std::vector<int> answer = solution(brown, yellow);
    if(answer == std::vector<int>({8, 6})){
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