#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long n, k;
    std::cin >> n >> k;

    long long lo = 1, hi = n*n, ans = 0;
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        long long cnt = 0;
        for(long long i = 1; i <= n; i++){
            cnt += std::min(n, mid/i);
        }

        if(cnt >= k){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    std::cout << ans << "\n";
    return 0;
}