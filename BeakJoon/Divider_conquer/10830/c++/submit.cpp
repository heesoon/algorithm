#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n; long long b;
const long long d = 1'000;
std::vector<std::vector<long long>> A;
std::vector<std::vector<long long>> X;

void printAns(const std::vector<std::vector<long long>> &a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

#if 0
const std::vector<std::vector<long long>> operator*(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b){
    std::vector<std::vector<long long>> R(a.size(), std::vector<long long>(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                R[i][j] += (a[i][k]*b[k][j]);
            }
        }
    }
    
    return R;
}
#endif

const std::vector<std::vector<long long>> operator*(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b){
    std::vector<std::vector<long long>> r(n, std::vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                r[i][j] += (a[i][k]*b[k][j]);
            }
            r[i][j] %= d;
        }
    }
    
    return r;
}

std::vector<std::vector<long long>> solve(long long n, const std::vector<std::vector<long long>> &a){
    if(n == 1){
        return A*X;
    }
    else{
        auto tmp = solve(n/2, a);
        if(n%2 == 0){
            return tmp*tmp;
        }
        else{
            return ((tmp*tmp)*a);
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> b;
    A.assign(n, std::vector<long long>(n, 0));
    X.assign(n, std::vector<long long>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) X[i][j] = 1;
        }
    }    

    auto ans = solve(b, A);
    printAns(ans);
    return 0;
}