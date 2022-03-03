#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> arr;

int solve(int n, int s){
    int ans = n+1;
    int lo = 0, hi = 0, sum = arr[0];

    while(lo <= hi && hi < n){
        if(sum < s){
            sum += arr[++hi];
        }
        else{
            ans = std::min(ans, hi-lo+1);
            sum -= arr[lo++];
        }
    }

    if(ans == n+1) ans = 0;

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N, S;
    std::cin >> N >> S;

    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::cout << solve(N, S) << "\n";
    return 0;
}