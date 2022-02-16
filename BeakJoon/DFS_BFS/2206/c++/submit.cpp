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
std::vector<std::vector<std::vector<bool>>> visited;

bool inRange(int y, int x){
    if((y >= 0 && y < n) && (x >= 0 && x < m)){
        return true;
    }
    return false;
}

int solve(){
    int ans = numeric_limits<int>::max()/2;
    std::queue<std::tuple<int,int,int>> Q;
    Q.push(std::make_tuple(0, 0, 0, 1));

    while(!Q.empty()){
        int fx = std::get<0>(Q.front());
        int fy = std::get<1>(Q.front());
        int fb = std::get<2>(Q.front()); // 벽을 부셨는지 아닌지
        int fd = std::get<3>(Q.front());

        if(fx == m-1 && fy == n-1){
            ans = std::min(ans, fd);
        }

        for(int i = 0; i < 4; i++){
            int nx = dx[i]+fx;
            int ny = dy[i]+fy;

            if(inRange(ny, nx) == true){
                if(map[ny][nx] == 0 && visited[ny][nx][fb] == false){
                    visited[ny][nx][fb] = true;
                    Q.push(ny, nx, fb, fd+1);
                }
                if(map[ny][nx] == 1 && && fb == 0 && visited[ny][nx][1] == false){
                    visited[ny][nx][1] = true;
                    Q.push(ny, nx, 1, fd+1);
                }
            }
        }        
    }

    return (ans == numeric_limits<int>::max()/2) ? -1 : ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    map.assing(n, std::vector<int>(m, 0));
    visited.assign(n, std::vector<std::vector<bool>>(m, std::vector<bool>(2, false)));
    for(int y = 0; y < n; y++){
        std::string str;
        std::cin >> str;
        for(int x = 0; x < m; x++){
            map[y][x] = str[x];
        }
    }

    std::cout < solve() << "\n";
    return 0;
}