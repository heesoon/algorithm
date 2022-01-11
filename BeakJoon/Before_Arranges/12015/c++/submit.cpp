#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> LIS;
std::vector<int> answer;

void solve(int n){
    int e;
    for(int i = 0; i < n; i++){
        std::cin >> e;

        if(LIS.empty()){
            LIS.push_back(e);
        }

        if(LIS.back() < e){
            LIS.push_back(e);
            //answer = LIS;
        }
        else{
            auto iter = std::lower_bound(LIS.begin(), LIS.end(), e);
            *iter = e;
        }
    }

    std::cout << LIS.size() << std::endl;
    //for(const auto &e : answer){
    //    std::cout << e << " ";
    //}
    //std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    LIS.assign(0, n);
    solve(n);
    return 0;
}