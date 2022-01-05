#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> DT;
std::vector<std::vector<int>> MAT;

int solve(int n){
    for(int i = 0; i < n; i++){
        DT[i][i] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j+i < n; j++){
            for(int k = j; k < j+i; k++){
                DT[j][j+i] = std::min(DT[j][j+i], DT[j][k] + DT[k+1][j+i] + MAT[j][0]*MAT[k][1]*MAT[i+j][1]);
            }
        }
    }
#if 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << DT[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif
    return DT[0][n-1];
}

int main(){
    int n;

    std::cin >> n;
    DT.assign(n, std::vector<int>(n, std::numeric_limits<int>::max()/2));
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