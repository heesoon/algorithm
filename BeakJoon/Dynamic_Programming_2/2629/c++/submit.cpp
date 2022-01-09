#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int MAX = 40'001;
std::vector<int> weights;
std::vector<std::vector<bool>> DT;

void solve(int n){
    DT[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < MAX; j++){
            if(j - weights[i-1] >= 0){
                DT[i][j] = DT[i-1][j] || DT[i-1][j-weights[i-1]];
            }
            else{
                DT[i][j] = DT[i-1][j];
            }

            if(weights[i-1] - j >= 0){
                DT[i][j] = DT[i][j] || DT[i-1][weights[i-1]-j];
            }            
        }
    }
#if 0
    for(int i = 0; i < 30; i++){
        std::cout << DT[n][i] << " ";
    }
#endif
}

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m, a;
    std::cin >> n;

    weights.assign(n, 0);
    DT.assign(n+1, std::vector<bool>(MAX, false));

    for(int i = 0; i < n; i++){
        std::cin >> weights[i];
    }

    std::cin >> m;
    solve(n);

    for(int i = 0; i < m; i++){
        std::cin >> a;
        if(DT[n][a] == true) std::cout << 'Y';
        else std::cout << 'N';
        std::cout << " ";
    }

    return 0;
}