#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<std::vector<char>> chess;

int getCount(int sy, int sx){
    int cnt = 0;
    char check[2];
    if((sy+sx)%2 == 0){
        if(chess[sy][sx] == 'W'){
            check[0] = 'W';
            check[1] = 'B';
        }
        else{
            check[0] = 'B';
            check[1] = 'W';            
        }
    }
    else{
        if(chess[sy][sx] == 'W'){
            check[0] = 'B';
            check[1] = 'W';
        }
        else{
            check[0] = 'W';
            check[1] = 'B';            
        }  
    }

    for(int y = sy; y < sy+8; y++){
        for(int x = sx; x < sx+8; x++){
            if((y+x)%2 == 0){
                if(check[0] != chess[y][x]){
                    cnt++;
                }
            }
            else{
                if(check[1] != chess[y][x]){
                    cnt++;
                }
            }
        }
    }

    return cnt;
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