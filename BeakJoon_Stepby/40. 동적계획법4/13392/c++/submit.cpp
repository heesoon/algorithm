#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int L = 10'001;

int n;
int a[L], b[L];
std::vector<std::vector<int>> DT(L, std::vector<int>(11, -1));

int solve(int i, int j){
    if(i == n) return 0;
    int &ret = DT[i][j];
    if(ret != -1) return ret;

    ret = 0;
    int lcnt = (b[i] - a[i] - j + 20) % 10;
    int rcnt = 10 - lcnt;

    return ret = std::min(solve(i+1, (j+lcnt)%10)+lcnt, solve(i+1, j)+rcnt);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::string sa, sb;
    std::cin >> n;
    std::cin >> sa >> sb;
    for(int i = 0; i < n; i++){
        a[i] = sa[i] - '0';
        b[i] = sb[i] - '0';
    }
    std::cout << solve(0, 0) << "\n";
    return 0;
}
