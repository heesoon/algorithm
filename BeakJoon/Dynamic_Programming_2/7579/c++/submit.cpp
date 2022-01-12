#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int MAX = 10'000'001;

std::vector<int> usedMemory;
std::vector<int> costs;
std::vector<std::vector<int>> DT;

int solve(int n, int m){
    DT[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < MAX; j++){
            if(j-usedMemory[i-1] >= 0) DT[i][j] = std::min(DT[i][j], DT[i-1][j-usedMemory[i-1]]+costs[i-1]);
            else DT[i][j] = DT[i-1][j];
        }
    }

    return DT[n][m];
}

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    usedMemory.assign(n, 0);
    costs.assign(n, 0);

    //DT.assign(n+1, std::vector<int>(MAX, std::numeric_limits<int>::max()/2));
    DT.assign(n+1, std::vector<int>(MAX, 10'000'001));

    for(int i = 0; i < n; i++){
        std::cin >> usedMemory[i]; 
    }

    for(int i = 0; i < n; i++){
        std::cin >> costs[i]; 
    }
    
    std::cout << solve(n, m) << "\n";

    return 0;
}