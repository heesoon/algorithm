#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int N = 16;
const int K = 101;
const int L = 51;
int n, k;
std::vector<std::vector<long long>> DT(1 << N, std::vector<long long>(K, -1));
std::vector<std::string> numsStr(N);
std::vector<int> numsSz(N);
std::vector<long long> numsRemainder(N);
std::vector<long long> power10Remainder(L);

long long solve(int visited, int num){
    if(visited == (1 << n)-1) return !num;
    long long &ret = DT[visited][num];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < n; i++){
        ret += solve(visited|(1<<i), (num*power10Remainder[numsSz[i]+numsRemainder[i]])%k);
    }

    return ret;
}

long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    long long denominator = 1, numerator = 0, number_gcd = 0;

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> numsStr[i];
        numsSz[i] = numsStr.size();
    }

    std::cin >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < numsSz[i]; j++){
            numsRemainder[i] = (numsRemainder[i]*10 + numsStr[i][j]-'0')%k;
        }
    }

    power10Remainder[0] = 0;
    for(int i = 1; i < L; i++){
        power10Remainder[i] = (power10Remainder[i-1]*10)%k;
    }

    numerator = solve(0, 0);
    for(int i = 2; i <= n; i++){
        denominator *= i;
    }

    number_gcd = gcd(numerator, denominator);

    std::cout << numerator/number_gcd << "/" << denominator/number_gcd << "\n";
    return 0;
}

// https://david0506.tistory.com/22