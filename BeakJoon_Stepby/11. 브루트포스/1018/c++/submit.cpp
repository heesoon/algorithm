#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<std::vector<char>> chess;

int getCount(int sy, int sx){
    int cntB = 0, cntW = 0;

    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            if((y+x)%2 == 0){
                // 8x8이 BWBW~~ 판과 비교해서 차이점
                if(chess[sy+y][sx+x] == 'W'){
                    cntB++;
                } //8x8이 WBWB~~ 판과 비교해서 차이점
                else{
                    cntW++;
                }
            }
            else{
                // 8x8이 BWBW~~ 판과 비교해서 차이점
                if(chess[sy+y][sx+x] == 'B'){
                    cntB++;
                }
                else{ //8x8이 WBWB~~ 판과 비교해서 차이점
                    cntW++;
                }                
            }
        }
    }

    return std::min(cntB, cntW);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m, ans = std::numeric_limits<int>::max()/2;
    std::cin >> n >> m;
    chess.assign(n, std::vector<char>(m));

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            std::cin >> chess[y][x];
        }
    }

    for(int y = 0; y+8 <= n; y++){
        for(int x = 0; x+8 <= m; x++){
            ans = std::min(ans, getCount(y, x));
        }
    }

    std::cout << ans << "\n";
    return 0;
}