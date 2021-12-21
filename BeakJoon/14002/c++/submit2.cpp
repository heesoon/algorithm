#include <iostream>
#include <vector>
#include <algorithm>

int S[1001];
int DT[1001];
std::vector<int> LIS[1001];

void solve(int n){
    int longestLen = 0, longestIdx = 0;
    for(int i = 0; i < n; i++){
        std::cin >> S[i];
        DT[i] = 1;
        LIS[i].push_back(S[i]);

        for(int j = 0; j < i; j++){
            if(S[i] > S[j]){
                if(DT[i] < DT[j]+1){
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(S[i]);
                    DT[i] = DT[j]+1;
                }
            }
        }

        if(longestLen < LIS[i].size()){
            longestLen = LIS[i].size();
            longestIdx = i;
        }
    }

    std::cout << longestLen << std::endl;
    for(const auto &e : LIS[longestIdx]){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    solve(n);
}

/*
8
30 1 9 40 7 5 4 90
*/