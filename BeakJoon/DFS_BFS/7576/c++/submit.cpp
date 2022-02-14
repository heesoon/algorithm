#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <tuple>

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
std::vector<std::vector<int>> map;
std::queue<std::tuple<int,int,int>> Q;

bool inRange(int y, int x){
    if((y >=0 && y < n) && (x >=0 && x < m)){
        return true;
    }
    return false;
}

void solve(){
    while(!Q.empty()){
        int fy = std::get<0>(Q.front());
        int fx = std::get<1>(Q.front());
        int fd = std::get<2>(Q.front());
        Q.pop();
        for(int i = 0; i < 4; i++){
            int ny = dy[i]+fy;
            int nx = dx[i]+fx;
            int nd = fd+1;

            if(inRange(ny, nx) == true && map[ny][nx] == 0){
                map[ny][nx] = nd;
                Q.push(std::make_tuple(ny, nx, nd));
            }
        }
    }
}

int check(){
    int ans = -1;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(map[y][x] == 0){
                return -1;
            }

            ans = std::max(ans, map[y][x]);
        }
    }
    
    if(ans == 1) return 0;
    else return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> m >> n;
    map.assign(n, std::vector<int>(m, 0));

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            std::cin >> map[y][x];
            if(map[y][x] == 1){
                Q.push(std::make_tuple(y, x, 0));
            }
        }
    }

    solve();

    std::cout << check() << "\n";
    return 0;
}