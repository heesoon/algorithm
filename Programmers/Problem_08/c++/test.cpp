#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    prices[prices.size() - 1] = 0;
    std::stack<int> stack;

    for(std::vector<int>::size_type i = 0; i < prices.size();){
            std::cout << "i : " << i << std::endl;
        if(!stack.empty()){
            if(prices[i] >= prices[stack.top()]){
                    std::cout << "push : " << i << ", " << stack.top() << std::endl;
                stack.push(i++);
            }
            else{
                int idx = stack.top();
                stack.pop();
                answer[idx] = i - idx;
                std::cout << "pop : " << idx << ", " << i << ", " << i - idx << std::endl;
            }
        }
        else{
                std::cout << "empty push : " << i << std::endl;
            stack.push(i++);
        }
    }

    return answer;
}


void tc1(){
    std::vector<int> prices = {1, 2, 3, 2, 3};

    std::vector<int> answer = solution(prices);
    if(answer == std::vector<int>({4, 3, 1, 1, 0})){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}