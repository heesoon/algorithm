#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<long long> heights;

long long getArea(int left, int right, int mid){
    int lo = mid;
    int hi = mid;

    long long height = heights[mid];
    long long maxArea = height;

    while(lo > left && hi < right){
        if(heights[lo-1] <= heights[hi+1]){
            hi++;
            height = std::min(height, heights[hi]);
        }
        else{
            lo--;
            height = std::min(height, heights[lo]);
        }

        maxArea = std::max(maxArea, height*(hi-lo+1));
    }

    while(hi < right){
        hi++;
        height = std::min(height, heights[hi]);
        maxArea = std::max(maxArea, height*(hi-lo+1));
    }

    while(lo > left){
        lo--;
        height = std::min(height, heights[lo]);
        maxArea = std::max(maxArea, height*(hi-lo+1));
    }

    return maxArea;
}

long long solve(int left, int right){
    if(left == right){
        return heights[left];
    }

    int mid = (left + right)/2;
    long long ret = std::max(solve(left, mid), solve(mid+1, right));

    ret = std::max(ret, getArea(left, right, mid));

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