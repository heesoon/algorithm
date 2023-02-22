#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

const int H = std::ceil(std::log2(500'000)); // 18.xx -> 19

// 희소 배열
int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int m;

    std::cin >> m;
    std::vector<std::vector<int>> vSparseTable(H+1, std::vector<int>(m+1, 0));

    for(int i = 1; i <= m; i++){
        std::cin >> vSparseTable[0][i];
    }

    for(int i = 1; i < H; i++){
        for(int j = 0; j <= m; j++){
            int prevParentIdx = vSparseTable[i-1][j];
            vSparseTable[i][j] = vSparseTable[i-1][prevParentIdx];
        }
    }

    int qNum;
    std::cin >> qNum;
    while(qNum--){
        int n, x;
        std::cin >> n >> x;
        for(int i = 0; n > 0; i++){
            if((n&1) == 1){
                x = vSparseTable[i][x];
            }
            n >>= 1;
        }

        std::cout << x << "\n";
    }

    return 0;
}

// reference : https://mangu.tistory.com/39?category=937146