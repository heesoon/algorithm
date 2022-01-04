#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> DT;
std::vector<std::vector<int>> MAT;

int solve(int n){
    for(int d = 1; d < n; d++){
        for(int i = 0; i+d < n; i++){
            for(int j = i+; j < n; j++){
                DT[i][j] = std::max(DT[i][j], )
            }
        }
    }
}

int main(){
    int n;

    std::cin >> n;
    DT.assign(n, std::vector<int>(n, 0));
    MAT.assign(n, std::vector<int>(2, 0));

    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        MAT[i][0] = a;
        MAT[i][1] = b;
    }

    std::cout << solve(n) << "\n";

    return 0;
}