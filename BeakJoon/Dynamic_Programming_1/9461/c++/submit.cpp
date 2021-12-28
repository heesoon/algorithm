#include <iostream>
#include <algorithm>

const int MAX = 101;
long long DT[MAX];

long long solve(int n){
    DT[1] = DT[2] = DT[3] = 1;
    DT[4] = DT[5] = 2;

    for(int i = 6; i <= n; i++){
        DT[i] = DT[i-1] + DT[i-5];
    }

    return DT[n];
}

int main(){
    int TC;
    int n;
    std::cin >> TC;
    for(int i = 0; i < TC; i++){
        std::cin >> n;
        std::fill((long long*)DT, (long long*)DT+n+1, 0);
        std::cout << solve(n) << "\n";
    }
    return 0;
}