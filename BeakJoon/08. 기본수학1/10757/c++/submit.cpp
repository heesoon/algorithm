#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::string A;
    std::string B;
    std::string C;
    int a = 0, b = 0, c = 0, d = 0, s = 0;
    std::cin >> A >> B;

    int len = std::max(A.size(), B.size());
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());

    for(int i = 0; i < len; i++){
        if(i < A.size()){
            a = A[i] - '0';
        }
        else{
            a = 0;
        }

        if(i < B.size()){
            b = B[i] - '0';
        }
        else{
            b = 0;
        }

        s = (a+b+c);
        c = s/10;
        d = s%10;

        C.insert(0, 1, (char)(d+48));
    }

    if(c != 0){
        C.insert(0, 1, (char)(c+48));
    }

    std::cout << C << "\n";
    return 0;
}