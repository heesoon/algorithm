#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int N = 31;
std::vector<int> DT(N, -1);

int solve(int n){
    if(n%2 != 0) return 0;

    DT[0] = 1, DT[2] = 3;
    for(int i = 4; i <= n; i++){
        if(i%2 != 0) continue;
        DT[i] = DT[i-2]*3;
        for(int j = i-4; j >= 0; j=j-2){
            DT[i] += DT[j]*2;
        }
    }

    return DT[n];
}

int main(){   
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::cout << solve(n) << "\n";
    return 0;
}

// https://mizzo-dev.tistory.com/entry/baekjoon2133