#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

int solve(int n){
    int ans = 0;
    int lo = 0, hi = 0, sum = 0;
    std::vector<bool> isPrime(n+1, true);
    std::vector<int> arrSum;
    arrSum.push_back(0); // 왜 0을 넣어줘야 하는지 이해 못함. 71%에서 틀림

    for(int i = 2; i <= std::sqrt(n); i++){
        for(int j = i*2; j <= n; j += i){
            isPrime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++){
        if(isPrime[i] == true){
            sum += i;
            arrSum.push_back(sum);
        }
    }

    while(lo <= hi && hi < arrSum.size()){
        if(arrSum[hi] - arrSum[lo] > n){
            lo++;
        }
        else if(arrSum[hi] - arrSum[lo] < n){
            hi++;
        }
        else{
            ans++;
            hi++;
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    std::cout << solve(N) << "\n";
    return 0;
}