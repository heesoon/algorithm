#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1'000'000'000;
int DT[501][101];

int solution(int n, int m, int a, int b, const vector<int> &row){
    int answer = 0;

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            DT[i][j] = MAX;
        }
    }

    for(int i = 0; i <= n; i++){
        DT[0]][i] = std::abs(j-a)*y;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                
            }
        }
    }    

    return answer;
}

void tc1(){
    int n = 4, m = 3, a = 2, b = 2, x = 1, y = 5;
    std::vector<int> row{1, 3, 2};

    if(2 == solution(n, m, a, b, row)){
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