#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> DT;
std::vector<int> pSum;
std::vector<int> novelCost;

int solve(int k){
    for(int i = 1; i <= k; i++){
        std::cin >> novelCost[i];
        pSum[i] = pSum[i-1] + novelCost[i];
    }

    for(int d = 1; d < k; d++){
        for(int i = 1; i+d <= k; i++){
            int j = i+d;
            DT[i][j] = std::numeric_limits<int>::max();
            for(int m = i; m < j; m++){
                DT[i][j] = std::min(DT[i][j], DT[i][m] + DT[m+1][j] + pSum[j] - pSum[i-1]);
            }
        }
    }

    return DT[1][k];
}

int main(){
    int c, k;
    std::cin >> c;
    for(int i = 0; i < c; i++){
        std::cin >> k;
        DT.assign(k+1, std::vector<int>(k+1, 0));
        pSum.assign(k+1, 0);
        novelCost.assign(k+1, 0);
        std::cout << solve(k) << std::endl;
    }
    return 0;
}

//https://js1jj2sk3.tistory.com/3