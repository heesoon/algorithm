#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<long long> A;
long long sumOfCuttedWood(long long height){
    long long sum = 0;
    for(auto it = A.begin(); it != A.end(); it++){
        if((*it) > height){
            sum += ((*it) - height);
        }
    }

    return sum;
}

long long solve(long long lowest, long long highest, long long target){
    long long lo = lowest, hi = highest, ans = 0;
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        if(sumOfCuttedWood(mid) >= target){
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
    long long n, m;
    std::cin >> n >> m;
    A.assign(n, 0);
    for(auto i = 0; i < n; i++){
        std::cin >> A[i];
    }

    auto maxHeight = *std::max_element(A.begin(), A.end());
    std::cout << solve(0, maxHeight, m);
    return 0;
}