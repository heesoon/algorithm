#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, ans;
    std::vector<int> nums;
    std::cin >> n;
    nums.assign(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> nums[i];
    }

    if(n == 1){
        ans = nums[0]*nums[0]; 
    }
    else{
        int a = *std::max_element(nums.begin(), nums.end());
        // int aIdx = std::max_element(nums.begin(), nums.end()) -nums.begin();
        int b = *std::min_element(nums.begin(), nums.end());

        ans = a*b;
    }

    std::cout << ans << "\n";
    return 0;
}