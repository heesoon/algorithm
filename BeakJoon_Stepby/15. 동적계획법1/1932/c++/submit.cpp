#include <iostream>
#include <algorithm>

const int MAX = 501;
int DT[MAX][MAX];
int Tri[MAX][MAX];

int solve(int n){
    int maxValue = 0;
    DT[0][0] = Tri[0][0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                DT[i][j] = std::max(DT[i][j], Tri[i][j]+DT[i-1][j]);
            }
            else if(j == i){
                DT[i][j] = std::max(DT[i][j], Tri[i][j]+DT[i-1][j-1]);
            }
            else{
                DT[i][j] = std::max({DT[i][j], Tri[i][j]+DT[i-1][j-1], Tri[i][j]+DT[i-1][j]});
            }

            //maxValue = std::max(maxValue, DT[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        if(maxValue < DT[n-1][i]){
            maxValue = DT[n-1][i];
        }
    }
    return maxValue;
}

int main(){
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            std::cin >> Tri[i][j];
        }
    }

    std::cout << solve(n) << "\n";

    return 0;
}