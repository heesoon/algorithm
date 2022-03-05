#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<long long> A;

long long cutCount(long long size){
    long long cnt = 0;
    for(auto i = 0; i < A.size(); i++){
        cnt += A[i]/size;
    }

    return cnt;
}

long long solve(long long low, long long high, long long k){
    long long lo = low, hi = high, ans = -1;
    while(lo <= hi){
        long long mid = (lo + hi)/2;
        if(cutCount(mid) >= k){
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
    long long n, k;
    std::cin >> n >> k;
    A.assign(n, 0);
    for(long long i = 0; i < n; i++){
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::cout << solve(1, A[n-1], k);
    return 0;
}