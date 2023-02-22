#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> infos(n);
    std::vector<int> ans(n, 1);
    for(int i = 0; i < n; i++){
        std::cin >> infos[i].first >> infos[i].second; 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(infos[i].first < infos[j].first && infos[i].second < infos[j].second){
                ans[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        std::cout << ans[i] << "\n";
    }

    return 0;
}