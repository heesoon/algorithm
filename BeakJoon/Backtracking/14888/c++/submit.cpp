#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

const int N = 12;
int minValue = std::numeric_limits<int>::max()/2;
int maxValue = std::numeric_limits<int>::min()/2;
std::vector<int> nums;
std::vector<int> operators;

void solve(int idx, int n, int sum){
    if(idx == n){
        if(sum > maxValue){
            maxValue = sum;
        }
        
        if(sum < minValue){
            minValue = sum;
        }

        return;
    }

    for(int i = 0; i < 4; i++){
        if(operators[i]){
            operators[i] -= 1;
            if(i == 0){
                solve(idx+1, n, sum+nums[idx]);
            }
            else if(i == 1){
                solve(idx+1, n, sum-nums[idx]);
            }
            else if(i == 2){
                solve(idx+1, n, sum*nums[idx]);
            }
            else{
                solve(idx+1, n, sum/nums[idx]);
            }            
            operators[i] += 1;
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    nums.assign(N, 0);
    operators.assign(4, 0);

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> nums[i];
    }

    for(int i = 0; i < 4; i++){
        std::cin >> operators[i];
    }

    solve(1, n, nums[0]);

    std::cout << maxValue << "\n";
    std::cout << minValue << "\n";

    return 0;
}