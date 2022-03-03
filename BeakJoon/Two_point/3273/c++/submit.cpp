#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> arr;

int solve(int n, int x){
    int ans = 0;
    std::sort(arr.begin(), arr.end());
    int lo = 0, hi = n-1;

    while(lo < hi){
        if(arr[lo] + arr[hi] == x){
            ans++;
            lo++;
            hi--;
        }
        else if(arr[lo] + arr[hi] > x){
            hi--;
        }
        else{
            lo++;
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, x;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    std::cin >> x;

    std::cout << solve(n, x) << "\n";

    return 0;
}