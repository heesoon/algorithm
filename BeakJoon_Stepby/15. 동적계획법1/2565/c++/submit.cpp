#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int MAX = 101;
int DT[MAX];
std::vector<std::pair<int,int>> lines;

int solve(int n){
    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        lines.push_back(std::make_pair(a, b));
    }

    std::sort(lines.begin(), lines.end(), [](const auto &a, const auto &b){
        return a.first < b.first;
    });

    for(int i = 0; i < n; i++){
        DT[i] = 1;
        for(int j = 0; j < i; j++){
            if(lines[i].second > lines[j].second){
                DT[i] = std::max(DT[i], DT[j]+1);
            }
        }
    }

    return n - *std::max_element(DT, DT+n);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
}