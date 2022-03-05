#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> A;

int lowerBound(int start, int end, int target){
    int sIdx = start, eIdx = end, ans = -1;

    while(sIdx <= eIdx){
        int mIdx = (sIdx+eIdx)/2;
        if(target == A[mIdx]){
            ans = mIdx;
            eIdx = mIdx-1;
        }
        else if(target < A[mIdx]){
            eIdx = mIdx-1;
        }
        else{
            sIdx = mIdx+1;
        }
    }

    return ans;
}

int upperBound(int start, int end, int target){
    int sIdx = start, eIdx = end, ans = -1;

    while(sIdx <= eIdx){
        int mIdx = (sIdx+eIdx)/2;
        if(target == A[mIdx]){
            ans = mIdx;
            sIdx = mIdx+1;
        }
        else if(target < A[mIdx]){
            eIdx = mIdx-1;
        }
        else{
            sIdx = mIdx+1;
        }
    }
    return ans;
}

int solve(int start, int end, int target){
    int lIdx = lowerBound(start, end, target);
    int uIdx = upperBound(start, end, target);
    
    //std::cout << lIdx << ", " << uIdx << std::endl;

    if(lIdx == -1 && uIdx == -1){
        return 0;
    }
    else{
        if(lIdx == uIdx){
            return 1;
        }
        else{
            return uIdx-lIdx+1;
        }
    }
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
        std::cout << solve(0, n-1, x) << " ";
    }    
    return 0;
}