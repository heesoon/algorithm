#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> A;
std::vector<int> DT;

int solve(int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                DT[i] = std::max(DT[i], DT[j]+1);
            }
        }
        ans = std::max(ans, DT[i]);
    }

    //for(const auto &x : DT){
    //    std::cout << x << " ";
    //}
    //std::cout << std::endl;
    return ans;
}

int main(){
    int N;
    int v;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> v;
        A.emplace_back(v);
    }

    DT.assign(N, 1);
    std::cout << solve(N) << std::endl;
}