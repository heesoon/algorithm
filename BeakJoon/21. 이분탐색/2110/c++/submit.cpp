#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<long long> X;

long long getCountRouter(long long dist){
    long long prev = X[0], cnt = 1;
    for(auto i = 1; i < X.size(); i++){
        if(X[i] - prev >= dist){
            cnt++;
            prev = X[i];
        }
    }

    return cnt;
}

long long solve(long long lowest, long long highest, long long target){
    long long lo = lowest, hi = highest, ans = 0;
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        if(getCountRouter(mid) >= target){
            ans = std::max(ans, mid);
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, c;
    std::cin >> n >> c;
    X.assign(n, 0);
    for(int i = 0; i < n; i++){
        std::cin >> X[i];
    }
    std::sort(X.begin(), X.end());
    std::cout << solve(1, X[n-1], c);
    return 0;
}