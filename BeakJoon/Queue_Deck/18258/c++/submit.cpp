#include <iostream>
#include <queue>
#include <algorithm>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::queue<int> Q;

    for(int i = 0; i < n; i++){
        std::string cmd;
        std::cin >> cmd;

        if(cmd == "push"){
            int x;
            std::cin >> x;
            Q.push(x);
        }
        else if(cmd == "pop"){
            if(!Q.empty()){
                std::cout << Q.front() << "\n";
                Q.pop();
            }
            else{
                std::cout << "-1" << "\n";
            }
        }        
        else if(cmd == "front"){
            if(!Q.empty()) std::cout << Q.front() << "\n";
            else std::cout << "-1" << "\n";
        }
        else if(cmd == "back"){
            if(!Q.empty()) std::cout << Q.back() << "\n";
            else std::cout << "-1" << "\n";
        }
        else if(cmd == "size"){
            std::cout << Q.size() << "\n";
        }
        else if(cmd == "back"){
            std::cout << Q.back() << "\n";
        }
        else if(cmd == "empty"){
            if(Q.empty()) std::cout << "1" << "\n";
            else std::cout << "0" << "\n";
        }
    }
    return 0;
}