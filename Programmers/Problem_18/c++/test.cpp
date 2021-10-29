#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    std::vector<int> have(n, 1);

    for(const auto idx : lost){
        have[idx - 1] -= 1;
    }

    for(const auto idx : reserve){
        have[idx - 1] += 1;
    }

    for(int i = 0; i < n; i++){
        if(have[i] == 0){
            if( i == 0){
                if(have[i+1] > 1){
                    have[i+1] -= 1;
                    have[i] += 1;
                }
            }
            else if(i == n -1){
                 if(have[i-1] > 1){
                    have[i-1] -= 1;
                    have[i] += 1;
                }               
            }
            else{
                if(have[i-1] > 1){
                    have[i-1] -= 1;
                    have[i] += 1;
                }
                else if(have[i+1] > 1){
                    have[i+1] -= 1;
                    have[i] += 1;
                }
            }
        }
    }

    answer = std::count_if(have.begin(), have.end(), [](int item){
        return item >= 1;
    });

    return answer;
}

void tc1(){
    int n = 5;
	std::vector<int> lost = {2, 4};
	std::vector<int> reserve = {1, 3, 5};

    int answer = solution(n, lost, reserve);
    if(answer == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int n = 5;
	std::vector<int> lost = {2, 4};
	std::vector<int> reserve = {3};

    int answer = solution(n, lost, reserve);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    int n = 3;
	std::vector<int> lost = {3};
	std::vector<int> reserve = {1};

    int answer = solution(n, lost, reserve);
    if(answer == 2){
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
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}
*/