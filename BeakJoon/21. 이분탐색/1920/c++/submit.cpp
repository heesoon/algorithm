#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> A;

int solve(int x, int n){
    int sIdx = 0, eIdx = n-1, ans = 0;

    while(sIdx <= eIdx){
        int mIdx = (sIdx+eIdx)/2;
        if(A[mIdx] == x){
            ans = 1;
            break;
        }
        else if(x < A[mIdx]){
            eIdx = mIdx-1;
        }
        else{
            sIdx = mIdx+1;
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n;
    A.assign(n, 0);
    for(int i = 0; i < n; i++){
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        std::cin >> x;
        std::cout << solve(x, n) << "\n";
    }
    return 0;
}