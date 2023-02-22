#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        int a, b, c;
        std::cin >> a >> b;

        int len = std::max(a, b);
        for(int j = len; j > 0; j--){
            if(a%j == 0 && b%j == 0){
                c = j;
                break;
            }
        }

        std::cout << c*(a/c)*(b/c) << "\n";
    }
    return 0;
}