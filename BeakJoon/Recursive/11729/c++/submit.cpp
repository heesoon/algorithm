#include <iostream>
#include <vector>
#include <algorithm>

int cnt;

void solve(int n, int s, int d){
    if(n == 1){
        std::cout << s << " " << d << "\n";
        return;
    }

    int tmp = 6 - s -d;
    solve(n-1, s, tmp);
    std::cout << s << " " << d << "\n";
    solve(n-1, tmp, d);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    std::cout << (1 << n)-1 << "\n";
    solve(n, 1, 3);
    return 0;
}
