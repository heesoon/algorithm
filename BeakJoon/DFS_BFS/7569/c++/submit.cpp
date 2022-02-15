#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <tuple>

const int L = 101;
int m, n, h;
int Box[L][L][L];
std::queue<std::tuple<int,int,int,int>> Q;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

bool inRange(int x, int y, int z){
    if((y >= 0 && y < n) && (x >= 0 && x < m) && (z >= 0 && z < h)){
        return true;
    }

    return false;
}

void solve(){
    while(!Q.empty()){
        int fx = std::get<0>(Q.front());
        int fy = std::get<1>(Q.front());
        int fz = std::get<2>(Q.front());
        int fd = std::get<3>(Q.front());
        Q.pop();

        for(int i = 0; i < 6; i++){
            int nx = dx[i]+fx;
            int ny = dy[i]+fy;
            int nz = dz[i]+fz;
            int nd = fd+1;

            if(inRange(nx, ny, nz) == true && Box[nz][ny][nx] == 0){
                Box[nz][ny][nx] = nd;
                Q.push(std::make_tuple(nx, ny, nz, nd));
            }           
        }
    }
}

int check(){
    int ans = -1;
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(Box[z][y][x] == 0){
                    return -1;
                }
                ans = std::max(ans, Box[z][y][x]);
            }
        }
    }

    if(ans == 1) return 0;
    else return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> m >> n >> h;
    for(int z = 0; z < h; z++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                std::cin >> Box[z][y][x];
                if(Box[z][y][x] == 1){
                    Q.push(std::make_tuple(x, y, z, 0));
                }
            }
        }
    }

    solve();

    std::cout << check() << "\n";
    return 0;
}