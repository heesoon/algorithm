#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> S;
std::vector<int> LIS;
std::vector<int> Index;
std::vector<int> Answer;

void solve(int n){
    int e;
    for(int i = 0; i < n; i++){
        std::cin >> e;
        S[i] = e;

        if(LIS.empty()){
            LIS.push_back(e);
            Index[0] = 0;
        }

        if(LIS.back() < e){
            LIS.push_back(e);
            Index[i] = LIS.size()-1;
        }
        else{
            auto iter = std::lower_bound(LIS.begin(), LIS.end(), e);
            *iter = e;
            int idx = iter - LIS.begin();
            Index[i] = idx;
        }
    }

    std::cout << LIS.size() << std::endl;
    int ldx = LIS.size()-1;
    for(int i = Index.size()-1; i >= 0; i--){
        if(Index[i] == ldx){
            //std::cout << S[i] << " ";
            Answer.push_back(S[i]);
            ldx--;
        }
    }
    //std::cout << std::endl;

    for(auto it = Answer.rbegin(); it != Answer.rend(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    S.assign(n, 0);
    //LIS.assign(0, n);
    Index.assign(n, 0);
    solve(n);
    return 0;
}