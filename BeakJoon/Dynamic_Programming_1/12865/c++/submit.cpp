#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::vector<std::pair<int,int>> DT;

int solve(int n, int k){
    int ans = 0;
    int a, b;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b;

        std::vector<std::pair<int,int>> TDT;
        for(const auto &p : DT){
            int na = p.first + a;
            int nb = p.second + b;
            TDT.push_back(std::make_pair(na, nb));
        }

        DT.insert(DT.begin(), TDT.begin(), TDT.end());

        DT.push_back(std::make_pair(a, b));
    }

    for(const auto &p : DT){
        //std::cout << p.first << " , " << p.second << std::endl;
        if(p.first <= k){
            if(ans < p.second){
                ans = p.second;
            }
        }
    }

    return ans;
}

int main(){
    int n, k;
    std::cin >> n >> k;

    std::cout << solve(n, k) << std::endl;
    return 0;
}