#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 16;
std::vector<bool> bColum(N, false);
std::vector<bool> bUpDiagonal(2*N, false);
std::vector<bool> bDownDiagonal(2*N, false);

int solve(int y, int n){
    int ret = 0;
    if(y == n-1){
        //std::cout << y << std::endl;
        return 1;
    }

    for(int nx = 0; nx < n; nx++){
        int ny = y+1;
        if(bColum[nx] == false && bUpDiagonal[nx+ny] == false && bDownDiagonal[n+(nx - ny)] == false){
            bColum[nx] = bUpDiagonal[nx+ny] = bDownDiagonal[n+(nx - ny)] = true;
            ret += solve(ny, n);
            bColum[nx] = bUpDiagonal[nx+ny] = bDownDiagonal[n+(nx - ny)] = false;
        }
    }

    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::cout << solve(-1, n) << "\n";
    return 0;
}