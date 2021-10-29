#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int rect = brown + yellow;

    for(int i = 1; i <= rect/2; i++){
        int x = 0;
        int y = 0;

        if(answer.empty() == false){
            break;
        }

        if(rect % i == 0){
            y = i;
            x = rect/i;
        }
        for(int j = 1; j <= yellow; j++){
            if(yellow % j == 0){
                int ny = j;
                int nx = yellow/j;

                if(y >= ny + 2 && x >= nx + 2){
                    answer.push_back(x);
                    answer.push_back(y);
                }
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
	int yellow = 1;

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

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int x=2;
    int y=brown/2-x;

    while(1){
        if((x-1)*(y-1)==yellow)
            break;
        x++;
        y--;
    }

    answer.push_back(y+1);
    answer.push_back(x+1);
    return answer;
}
*/