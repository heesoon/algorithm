#include <iostream>
#include <vector>
#include <algorithm>

int N = 4;
int W[101] = {2, 1, 3, 2, };
int V[101] = {3, 2, 3, 2, };
std::vector<std::vector<int>> DT(101, std::vector<int>(1001, 0));

int f(int n, int w){

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= w; j++){
            if(j < W[i]){
                DT[i][j] = DT[i+1][j];
            }
            else{
                DT[i][j] = std::max(DT[i+1][j], DT[i+1][j-W[i]] + V[i]);
            }
        }
    }

    return DT[0][w];
}

void tc1(){
    int target = 5;
    if(7 == f(N, target)){
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