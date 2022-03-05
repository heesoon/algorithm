#include <iostream>
#include <deque>
#include <algorithm>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin >> tc;

    for(int i = 0; i < tc; i++){
        std::string func; int n;
        bool berr = false;
        std::deque<int> dq;
        std::cin >> func;
        std::cin >> n;

        for(int j = 0; j < n; j++){
            int x;
            std::cin >> x;
            dq.push_back(x);
        }

        int direction = 1;
        for(auto j = 0; j < func.size(); j++){
            if(func[j] == 'R'){
                direction++;
            }
            else if(func[j] == 'D'){
                if((direction%2) == 1){
                    // -> direction
                    if(dq.empty()){
                        berr = true;
                        break;
                    }
                    else{
                        dq.pop_front();
                    }
                }
                else{
                    // <- direction
                    if(dq.empty()){
                        berr = true;
                        break;
                    }
                    else{
                        dq.pop_back();
                    }
                }
            }
        }

        if(berr == true){
            std::cout << "error" << "\n";
        }
        else{
            if((direction%2) == 1){
                // -> direction
                std::cout << "[";
                while(!dq.empty()){
                    if(dq.size() == 1) std::cout << dq.front();
                    else std::cout << dq.front() << ",";
                    dq.pop_front();
                }
                std::cout << "]\n";
            }
            else{
                // <- direction
                std::cout << "[";
                while(!dq.empty()){
                    if(dq.size() == 1) std::cout << dq.back();
                    else std::cout << dq.back() << ",";
                    dq.pop_back();
                }
                std::cout << "]\n";
            }
        }
    }
    return 0;
}