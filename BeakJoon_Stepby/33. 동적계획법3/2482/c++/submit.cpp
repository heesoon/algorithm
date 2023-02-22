#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int M = 1'000'000'003;
std::vector<std::vector<int>> DT;

int solve(int n, int k){
    int &ret = DT[n][k];
    if(n <= 0 || n < 2*k){
        return ret = 0;
    }
    if(k == 1){
        return ret = n;
    }

    if(ret != -1) return ret;

    return ret = (solve(n-2, k-1) + solve(n-1, k))%M;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N, K;
    std::cin >> N;
    std::cin >> K;
    DT.assign(N+1, std::vector<int>(N+1, -1));
    std::cout << solve(N, K) << "\n";
    return 0;
}