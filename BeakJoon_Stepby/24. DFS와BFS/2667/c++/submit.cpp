#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int n, cnt;
std::vector<std::vector<int>> map;
std::vector<int> ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool inRange(int y, int x){
    if((y >=0 && y < n) && (x >=0 && x < n)){
        return true;
    }
    return false;
}

int solve(int y, int x){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if(inRange(ny, nx) == true && map[ny][nx] == 1){
            map[ny][nx] = cnt;
            ret += solve(ny, nx)+1;
        }
    }
    
    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    map.assign(n, std::vector<int>(n, 0));
    for(int y = 0; y < n; y++){
        std::string str;
        std::cin >> str;
        for(auto x = 0; x < str.size(); x++){
            map[y][x] = str[x] - '0';
        }
    }

    cnt = 2;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(map[y][x] == 1){
                map[y][x] = cnt;
                int r = solve(y, x)+1;
                ans.push_back(r);
                cnt++;
            }
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout << cnt-2 << "\n";
    for(auto it = ans.begin(); it != ans.end(); it++){
        std::cout << *it << "\n";
    }
    return 0;
}