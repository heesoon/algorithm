#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::string ans;
std::vector<std::vector<char>> map;

bool isSame(int y, int x, int len){
    for(int i = y; i < y+len; i++){
        for(int j = x; j < x+len; j++){
            if(map[y][x] != map[i][j]){
                return false;
            }
        }
    }

    return true;
}

void solve(int y, int x, int len){
    if(isSame(y, x, len) == true){
        ans += map[y][x];
        return;
    }

    ans += '(';
    solve(y, x, len/2);
    solve(y, x+len/2, len/2);
    solve(y+len/2, x, len/2);
    solve(y+len/2, x+len/2, len/2);
    ans += ')';
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    map.assign(n, std::vector<char>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> map[i][j];
        }
    }

    solve(0, 0, n);

    std::cout << ans << "\n";
    return 0;
}