#include <iostream>
#include <vector>
#include <algorithm>

const int N = 100 + 1;
const int C = 100 + 1;
std::vector<int> usedMem;
std::vector<int> cost;
std::vector<std::vector<int>> DT(N, std::vector<int>(N*C, 0));

int solution(int n, int m){
    int answer = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= N*C; j++){
            if(j < cost[i]){
                DT[i][j] = DT[i-1][j];
            }
            else{
                DT[i][j] = std::max(DT[i-1][j], DT[i-1][j - cost[i]] + usedMem[i]);
            }
        }
    }

    for(int i = 0; i <= N*C; i++){
        if(DT[n-1][i] >= m){
            break;
        }

        answer = i;
    }

    return answer;
}

void tc1(){
    int n = 5;
    int m = 60;
    usedMem.assign({30, 10, 20, 35, 40});
    cost.assign({3, 0, 3, 5, 4});

    if(6 == solution(n, m)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}