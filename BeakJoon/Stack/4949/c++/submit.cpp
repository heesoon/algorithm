#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    while(1){
        std::stack<char> st;
        std::string str;
        bool bflag = true;
        std::cin.ignore();
        std::getline(std::cin, str, '.');
        if(str.size() == 0){
            break;
        }

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']'){
                if(st.empty() == true){
                    bflag = false;
                    break;
                }
                else{
                    if(st.top() == '(' && str[i] == ')'){
                        st.pop();
                    }
                    else if(st.top() == '[' && str[i] == ']'){
                        st.pop();
                    }
                    else{
                        bflag = false;
                        break;
                    }
                }
            }
        }

        if(bflag == false){
            std::cout << "no" << "\n";
        }
        else{
            if(st.empty() == true){
                std::cout << "yes" << "\n";
            }
            else{
                std::cout << "no" << "\n";
            }
        }
    }
    return 0;
}