#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<long long> heights;

long long solve(int left, int right){
    if(left == right){
        return heights[left];
    }

    int mid = (left + right)/2;
    long long ret = std::max(solve(left, mid), solve(mid+1, right));

    int lo = mid, hi = mid+1;
    long long height = std::min(heights[lo], heights[hi]);

    ret = std::max(ret, height*2);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || heights[lo-1] < heights[hi+1])){
            hi++;
            height = std::min(height, heights[hi]);
        }
        else{
            lo--;
            height = std::min(height, heights[lo]);
        }
    }

    ret = std::max(ret, height*(hi-lo+1));
    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);

    while(1){
        int n;
        std::cin >> n;
        if(n == 0){
            break;
        }
        heights.assign(n, 0);

        for(int i = 0; i < n; i++){
            std::cin >> heights[i];
        }

        std::cout << solve(0, n-1) << "\n";
        heights.clear();
    }

    return 0;
}

// https://www.acmicpc.net/blog/view/12
// https://bingorithm.tistory.com/14
// https://st-lab.tistory.com/255