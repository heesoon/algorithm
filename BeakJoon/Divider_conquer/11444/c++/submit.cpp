#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

const long long mod = 1'000'000'007;
std::vector<std::vector<long long>> Base ={{1, 1}, {1, 0}};
std::vector<std::vector<long long>> Diag ={{1, 0}, {0, 1}};

const std::vector<std::vector<long long>> operator*(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b){
    std::vector<std::vector<long long>> r(2, std::vector<long long>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                r[i][j] += (a[i][k]*b[k][j]);
            }
            r[i][j] %= mod;
        }
    }
    return r;
}

const std::vector<std::vector<long long>> solve(long long n){
    if(n == 1){
        return Base*Diag;
    }
    else{
        auto t = solve(n/2);
        if(n%2 == 0){
            return (t*t);
        }
        else{
            return ((t*t)*Base);
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long n;
    std::cin >> n;

    auto ans = solve(n);

    std::cout << ans[1][0] << "\n";
    return 0;
}