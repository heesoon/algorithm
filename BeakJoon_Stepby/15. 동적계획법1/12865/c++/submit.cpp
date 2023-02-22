#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int WMAX = 100'001;
std::vector<std::vector<int>> DT;
std::vector<int> W;
std::vector<int> V;

int solve(int n, int k){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        std::cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j-W[i] >= 0) DT[i][j] = std::max(DT[i-1][j], DT[i-1][j-W[i]]+V[i]);
            else DT[i][j] = DT[i-1][j];
        }
    }

    for(int j = 0; j <= k; j++){
        ans = std::max(ans, DT[n][j]);
    }

    return ans;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    DT.assign(n+1, std::vector<int>(WMAX, 0));
    W.assign(n+1, 0);
    V.assign(n+1, 0);
    std::cout << solve(n, k) << std::endl;
    return 0;
}