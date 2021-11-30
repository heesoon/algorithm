#include <iostream>
#include <vector>
#include <algorithm>

int N = 4;
int W[101] = {2, 1, 3, 2, };
int V[101] = {3, 2, 3, 2, };
std::vector<std::vector<int>> DT(101, std::vector<int>(1001, -1));

int f(int idx, int r){
#if 0    
    if(idx == N){
        return 0;
    }
    else if(W[idx] <= r){
        return std::max(f(idx+1, r), f(idx+1, r-W[idx]) + V[idx]);
    }
    else{
        return f(idx+1, r);
    }
#else
    if(DT[idx][r] != -1){
        return DT[idx][r];
    }
    if(idx == N){
        return DT[idx][r] = 0;
    }
    else if(W[idx] <= r){
        return DT[idx][r] = std::max(f(idx+1, r), f(idx+1, r-W[idx]) + V[idx]);
    }
    else{
        return DT[idx][r] = f(idx+1, r);
    }
#endif
}

void tc1(){
    int target = 5;
    if(7 == f(0, target)){
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