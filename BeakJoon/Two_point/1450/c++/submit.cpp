#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int N;
long long C;
std::vector<long long> vOrigin;

void solve(int lo, int hi, long long sum, std::vector<long long> &vSum){
    if(sum > C) return;

    if(lo == hi){
        vSum.push_back(sum);
        return;
    }

    solve(lo+1, hi, sum, vSum);
    solve(lo+1, hi, sum+vOrigin[lo], vSum);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long ans = 0;
    std::vector<long long> vLeft;
    std::vector<long long> vRight;

    std::cin >> N >> C;

    vOrigin.assign(N, 0);
    for(int i = 0; i < N; i++){
        std::cin >> vOrigin[i];
    }

    solve(0, N/2, 0, vLeft);
    solve(N/2, N, 0, vRight);

    std::sort(vRight.begin(), vRight.end());

    for(int i = 0; i < vLeft.size(); i++){
        long long x = C - vLeft[i];
        long long pos = std::upper_bound(vRight.begin(), vRight.end(), x) - vRight.begin();
        ans += pos;
    }

    std::cout << ans << "\n";
    return 0;
}

// referenc : https://technicolour.tistory.com/8